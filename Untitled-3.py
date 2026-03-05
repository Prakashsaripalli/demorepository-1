class Animal:
 def speak(self):
     print("Animal will speak in different sounds")
class Dog(Animal):
 def speak(self):
     print("Dog barks:Bow Bow")  
class Cat(Animal):
 def speak(self):
     print("Cat sounds like :Meow Meow")
class bird(Animal):
 def speak(self):
     print("Bird sounds like :Chirp Chirp")
Animals = [Dog(), Cat(), bird()]
for animal in Animals:
    animal.speak()