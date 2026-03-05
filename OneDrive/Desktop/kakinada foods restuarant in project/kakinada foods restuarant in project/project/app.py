from flask import Flask, render_template, request, redirect, url_for, session, flash
from pymongo import MongoClient
from datetime import datetime
from bson import ObjectId
from bson.errors import InvalidId

app = Flask(__name__)
app.secret_key = 'your_secret_key'  # Replace with a secure key in production
ADMIN_EMAIL = 'kumarsaripalli1198@gmail.com'
ADMIN_PASSWORD = '123456'

# MongoDB configuration
client = MongoClient('mongodb://localhost:27017')  # Replace with your MongoDB URI
db = client['food_haven']
users_collection = db['users']
contacts_collection = db['contacts']
subscriptions_collection = db['subscriptions']
orders_collection = db['orders']
items_collection = db['items']

# Sample food data
foods = [
    
    {'name': 'Chicken Biryani', 'price': 30, 'description': 'The traditional process of Chicken Biryani starts by marinating meat in yogurt along with spices and herbs.'},
    {'name': 'Chicken Lollipop', 'price': 20, 'description': 'Chicken lollipop is a popular Indo-Chinese fried chicken appetizer.'},
    {'name': 'Masala Fish Fry', 'price': 10, 'description': 'A fish fry is a meal containing battered or breaded fried fish.'},
    {'name': 'Chicken Manchurian', 'price': 22, 'description': 'Manchurian is a class of Indian Chinese dishes made by roughly chopping and paneer.'},
    {'name': 'Black Pepper Crab', 'price': 12, 'description': 'Crabs can be prepared in many different ways, including steamed, boiled, grilled, or fried.'},
    {'name': 'Lobster Malay Curry', 'price': 30, 'description': 'Lobster is a type of shellfish that people typically prepare by boiling or steaming.'},
    {'name': 'Premium Mandhi Small', 'price': 100, 'description': 'Premium small mandi serving with aromatic rice and spiced chicken.'},
    {'name': 'Premium Mandhi Medium', 'price': 200, 'description': 'Premium medium mandi platter for shared dining.'},
    {'name': 'Premium Mandhi Full', 'price': 500, 'description': 'Premium full mandi feast for family-sized serving.'}
]

food_ingredients = {
    'Chicken Biryani': ['Basmati rice', 'Chicken', 'Yogurt', 'Onion', 'Ginger garlic paste', 'Biryani masala', 'Mint leaves', 'Coriander leaves', 'Ghee'],
    'Chicken Lollipop': ['Chicken wings', 'Corn flour', 'All-purpose flour', 'Ginger garlic paste', 'Soy sauce', 'Chili sauce', 'Pepper powder', 'Salt', 'Oil'],
    'Masala Fish Fry': ['Fish fillets', 'Red chili powder', 'Turmeric', 'Lemon juice', 'Ginger garlic paste', 'Rice flour', 'Salt', 'Oil'],
    'Chicken Manchurian': ['Chicken', 'Corn flour', 'All-purpose flour', 'Soy sauce', 'Garlic', 'Ginger', 'Spring onions', 'Tomato ketchup', 'Oil'],
    'Black Pepper Crab': ['Crab', 'Black pepper', 'Garlic', 'Butter', 'Soy sauce', 'Onion', 'Salt'],
    'Lobster Malay Curry': ['Lobster', 'Coconut milk', 'Onion', 'Tomato', 'Curry leaves', 'Turmeric', 'Chili powder', 'Coriander powder', 'Oil'],
    'Premium Mandhi Small': ['Basmati rice', 'Chicken', 'Mandhi spice mix', 'Saffron', 'Onion', 'Tomato', 'Ghee', 'Dry lime', 'Nuts'],
    'Premium Mandhi Medium': ['Basmati rice', 'Chicken', 'Mandhi spice mix', 'Saffron', 'Onion', 'Tomato', 'Ghee', 'Dry lime', 'Nuts'],
    'Premium Mandhi Full': ['Basmati rice', 'Whole chicken', 'Mandhi spice mix', 'Saffron', 'Onion', 'Tomato', 'Ghee', 'Dry lime', 'Mint']
}

food_images = {
    'Chicken Biryani': 'https://www.cubesnjuliennes.com/wp-content/uploads/2020/07/Chicken-Biryani-Recipe.jpg',
    'Chicken Lollipop': 'https://www.licious.in/blog/wp-content/uploads/2022/02/shutterstock_761402230.jpg',
    'Masala Fish Fry': 'https://s3-ap-south-1.amazonaws.com/betterbutterbucket-silver/anjali-padhy15307041455b3cb110f5a30.jpeg',
    'Chicken Manchurian': 'https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTf8ZlDkwK11DFkE7a4wp9F2K2P9-8_R2tJPA&s',
    'Black Pepper Crab': 'https://bellyrumbles.com/wp-content/uploads/2020/06/chilli-mud-crab-recipe.jpg',
    'Lobster Malay Curry': 'https://www.foodandwine.com/thmb/GoBIGshvdMQbYoCHVJWE_V9fQGY=/1500x0/filters:no_upscale():max_bytes(150000):strip_icc()/lobster-gnudi-xl-recipe2017-bf67e84ea3c649b18ec1d087d71f5b31.jpg',
    'Premium Mandhi Small': 'https://cdn.siasat.com/wp-content/uploads/2023/10/mandi-hyderabad.jpg',
    'Premium Mandhi Medium': 'https://img.freepik.com/premium-photo/chicken-mandi-biryani-served-dish-isolated-dark-background-side-view-arabic-food_689047-793.jpg',
    'Premium Mandhi Full': 'https://i.pinimg.com/736x/6e/1d/f5/6e1df59b110d5734f580fd61d592fbe5.jpg'
}

@app.route('/')
def index():
    if 'username' in session:
        return redirect(url_for('home'))
    return redirect(url_for('login'))

@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        login_mode = request.form.get('login_mode', 'admin').strip().lower()
        # Accept either username or email from the same field.
        identifier = request.form['username'].strip()
        password = request.form['password']

        if login_mode == 'admin':
            # Fixed admin login
            if identifier.lower() == ADMIN_EMAIL.lower() and password == ADMIN_PASSWORD:
                session['username'] = 'admin'
                session['is_admin'] = True
                flash('Admin login successful!', 'success')
                return redirect(url_for('profile'))

            flash('Invalid admin credentials', 'danger')
            return redirect(url_for('login'))

        user = users_collection.find_one({
            '$or': [
                {'username': identifier},
                {'email': identifier}
            ]
        })

        if user and user['password'] == password:
            session['username'] = user['username']
            session.pop('is_admin', None)
            flash('Login successful!', 'success')
            return redirect(url_for('home'))
        else:
            flash('Invalid username/email or password', 'danger')
            return redirect(url_for('login'))

    return render_template('login.html')

@app.route('/register', methods=['GET', 'POST'])
def register():
    if request.method == 'POST':
        username = request.form['username']
        email = request.form['email']
        password = request.form['password']

        if users_collection.find_one({'username': username}):
            flash('Username already exists', 'danger')
            return redirect(url_for('register'))

        users_collection.insert_one({
            'username': username,
            'email': email,
            'password': password
        })
        
        flash('Registration successful! You can now log in.', 'success')
        return redirect(url_for('login'))

    return render_template('register.html')

@app.route('/forgot-password', methods=['GET', 'POST'])
def forgot_password():
    global ADMIN_PASSWORD

    if request.method == 'POST':
        account_type = request.form.get('account_type', 'user').strip().lower()
        identifier = request.form.get('identifier', '').strip()
        new_password = request.form.get('new_password', '').strip()
        confirm_password = request.form.get('confirm_password', '').strip()

        if not identifier or not new_password or not confirm_password:
            flash('All fields are required.', 'danger')
            return redirect(url_for('forgot_password'))

        if new_password != confirm_password:
            flash('Passwords do not match.', 'danger')
            return redirect(url_for('forgot_password'))

        if account_type == 'admin':
            if identifier.lower() != ADMIN_EMAIL.lower():
                flash('Admin email not found.', 'danger')
                return redirect(url_for('forgot_password'))

            ADMIN_PASSWORD = new_password
            flash('Admin password reset successful. Please login.', 'success')
            return redirect(url_for('login'))

        user = users_collection.find_one({
            '$or': [
                {'username': identifier},
                {'email': identifier}
            ]
        })
        if not user:
            flash('User not found.', 'danger')
            return redirect(url_for('forgot_password'))

        users_collection.update_one(
            {'_id': user['_id']},
            {'$set': {'password': new_password}}
        )
        flash('User password reset successful. Please login.', 'success')
        return redirect(url_for('login'))

    return render_template('forgot_password.html')

@app.route('/home')
def home():
    if 'username' not in session:
        flash('You must be logged in to view this page.', 'danger')
        return redirect(url_for('login'))
    if session.get('is_admin'):
        return redirect(url_for('profile'))
    return render_template('home.html', username=session['username'])

@app.route('/food-details')
def food_details():
    if 'username' not in session:
        flash('You must be logged in to view this page.', 'danger')
        return redirect(url_for('login'))

    food_name = request.args.get('food_name', '').strip()
    if not food_name:
        flash('Food item not selected.', 'danger')
        return redirect(url_for('home'))

    selected_food = next((food for food in foods if food['name'].lower() == food_name.lower()), None)
    if not selected_food:
        flash('Food item not found.', 'danger')
        return redirect(url_for('home'))

    ingredients = food_ingredients.get(selected_food['name'], ['Ingredients will be updated soon.'])
    detail_image = food_images.get(
        selected_food['name'],
        'https://images.unsplash.com/photo-1517248135467-4c7edcad34c4?auto=format&fit=crop&w=1400&q=80'
    )
    return render_template('food_details.html', food=selected_food, ingredients=ingredients, detail_image=detail_image)

@app.route('/profile')
def profile():
    if 'username' not in session:
        flash('You must be logged in to view this page.', 'danger')
        return redirect(url_for('login'))

    username = session['username']
    is_admin = session.get('is_admin', False)

    if is_admin:
        user = {
            'username': 'admin',
            'email': ADMIN_EMAIL,
            'role': 'Administrator'
        }
        created_items = list(items_collection.find().sort('created_at', -1))
        all_orders = list(orders_collection.find().sort([('table_number', 1), ('ordered_at', 1)]))

        table_groups = {}
        for order in all_orders:
            table_no = (order.get('table_number') or 'N/A').strip() or 'N/A'
            if table_no not in table_groups:
                table_groups[table_no] = {
                    'table_number': table_no,
                    'orders': [],
                    'total_price': 0,
                    'all_paid': True
                }

            price = float(order.get('price', 0))
            table_groups[table_no]['orders'].append({
                'food_name': order.get('food_name', '-'),
                'price': price,
                'username': order.get('username', '-'),
                'order_description': order.get('order_description', '-')
            })
            table_groups[table_no]['total_price'] += price
            if not order.get('is_paid', False):
                table_groups[table_no]['all_paid'] = False

        grouped_orders = [table_groups[key] for key in sorted(table_groups.keys())]
        return render_template(
            'profile.html',
            user=user,
            is_admin=True,
            created_items=created_items,
            grouped_orders=grouped_orders
        )

    user = users_collection.find_one({'username': username})
    orders = list(orders_collection.find({'username': username}).sort('ordered_at', -1))
    return render_template('profile.html', user=user, is_admin=False, orders=orders)

@app.route('/admin/create-item', methods=['POST'])
def admin_create_item():
    if 'username' not in session or not session.get('is_admin'):
        flash('Admin access required.', 'danger')
        return redirect(url_for('login'))

    name = request.form.get('name', '').strip()
    price_text = request.form.get('price', '').strip()
    description = request.form.get('description', '').strip()
    ingredients_text = request.form.get('ingredients', '').strip()
    image_url = request.form.get('image_url', '').strip()

    if not name or not price_text or not description:
        flash('Name, price and description are required.', 'danger')
        return redirect(url_for('profile'))

    try:
        price = float(price_text)
    except ValueError:
        flash('Price must be a valid number.', 'danger')
        return redirect(url_for('profile'))

    ingredients = [item.strip() for item in ingredients_text.split(',') if item.strip()]
    if not ingredients:
        ingredients = ['Ingredients will be updated soon.']

    items_collection.insert_one({
        'name': name,
        'price': price,
        'description': description,
        'ingredients': ingredients,
        'image_url': image_url,
        'created_at': datetime.utcnow()
    })

    # Keep in-memory sources updated for current process.
    existing_food = next((food for food in foods if food['name'].lower() == name.lower()), None)
    if not existing_food:
        foods.append({'name': name, 'price': price, 'description': description})
    food_ingredients[name] = ingredients
    if image_url:
        food_images[name] = image_url

    flash('Item created successfully.', 'success')
    return redirect(url_for('profile'))

@app.route('/admin/table-paid', methods=['POST'])
def admin_table_paid():
    if 'username' not in session or not session.get('is_admin'):
        flash('Admin access required.', 'danger')
        return redirect(url_for('login'))

    table_number = request.form.get('table_number', '').strip()
    if not table_number:
        flash('Table number missing.', 'danger')
        return redirect(url_for('profile'))

    result = orders_collection.update_many(
        {'table_number': table_number},
        {'$set': {'is_paid': True, 'paid_at': datetime.utcnow()}}
    )
    if result.matched_count:
        flash(f'Table {table_number} marked as paid.', 'success')
    else:
        flash('No orders found for selected table.', 'danger')
    return redirect(url_for('profile'))

@app.route('/admin/table-remove', methods=['POST'])
def admin_table_remove():
    if 'username' not in session or not session.get('is_admin'):
        flash('Admin access required.', 'danger')
        return redirect(url_for('login'))

    table_number = request.form.get('table_number', '').strip()
    if not table_number:
        flash('Table number missing.', 'danger')
        return redirect(url_for('profile'))

    result = orders_collection.delete_many({'table_number': table_number})
    if result.deleted_count:
        flash(f'Orders removed for table {table_number}.', 'success')
    else:
        flash('No orders found for selected table.', 'danger')
    return redirect(url_for('profile'))

@app.route('/cancel-order/<order_id>', methods=['POST'])
def cancel_order(order_id):
    if 'username' not in session:
        flash('You must be logged in to view this page.', 'danger')
        return redirect(url_for('login'))

    try:
        order_object_id = ObjectId(order_id)
    except InvalidId:
        flash('Invalid order id.', 'danger')
        return redirect(url_for('profile'))

    result = orders_collection.delete_one({
        '_id': order_object_id,
        'username': session['username']
    })

    if result.deleted_count:
        flash('Order cancelled successfully.', 'success')
    else:
        flash('Order not found.', 'danger')

    return redirect(url_for('profile'))

@app.route('/about')
def about():
    return render_template('about.html')

@app.route('/contact', methods=['GET', 'POST'])
def contact():
    if request.method == 'POST':
        name = request.form['name']
        email = request.form['email']
        subject = request.form['subject']
        message = request.form['message']

        # Store contact form data in MongoDB
        contacts_collection.insert_one({
            'name': name,
            'email': email,
            'subject': subject,
            'message': message
        })

        flash('Your message has been sent successfully!', 'success')
        return redirect(url_for('contact'))

    return render_template('contact.html')

@app.route('/subscribe', methods=['POST'])
def subscribe():
    if 'username' not in session:
        flash('You must be logged in to subscribe.', 'danger')
        return redirect(url_for('login'))

    email = request.form.get('email', '').strip()
    if not email:
        flash('Please enter your email.', 'danger')
        return redirect(url_for('home'))

    # Avoid duplicate subscriptions.
    if not subscriptions_collection.find_one({'email': email}):
        subscriptions_collection.insert_one({
            'email': email,
            'username': session['username']
        })

    flash('Subscribed successfully!', 'success')
    return redirect(url_for('home'))

@app.route('/logout')
def logout():
    session.pop('username', None)
    session.pop('is_admin', None)
    flash('You have been logged out.', 'info')
    return redirect(url_for('login'))

@app.route('/buy', methods=['GET', 'POST'])
def buy():
    if 'username' not in session:
        flash('You must be logged in to view this page.', 'danger')
        return redirect(url_for('login'))

    if request.method == 'POST':
        food_name = request.form['food_name'].strip()
        table_number = request.form.get('table_number', '').strip()
        order_description = request.form.get('order_description', '').strip()

        selected_food = next((food for food in foods if food['name'] == food_name), None)
        if not selected_food:
            flash('Invalid food selected.', 'danger')
            return redirect(url_for('buy'))

        orders_collection.insert_one({
            'username': session['username'],
            'food_name': food_name,
            'price': selected_food['price'],
            'table_number': table_number,
            'order_description': order_description,
            'is_paid': False,
            'ordered_at': datetime.utcnow()
        })

        flash(f'You have ordered {food_name}!', 'success')
        return redirect(url_for('buy'))
    
    selected_food_name = request.args.get('food_name', '').strip()
    if selected_food_name:
        filtered_foods = [food for food in foods if food['name'].lower() == selected_food_name.lower()]
        if filtered_foods:
            return render_template('buy.html', foods=filtered_foods)
        flash('Selected item not found. Showing all items.', 'info')

    return render_template('buy.html', foods=foods)

if __name__ == '__main__':
    app.run(debug=True)

