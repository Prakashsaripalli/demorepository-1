class BankAccount:
    def __init__(self,Accno,AccName,ifseCode,Balance):
        self.Accno = Accno
        self.AccName =  AccName
        self.ifseCode = ifseCode
        self.Balance = Balance
    def display(self):
        print("My Accno is:",self.Accno)
        print("My AccName is:",self.AccName)
        print("My ifseCode is:",self.ifseCode)
        print("My Balance is:",self.Balance)

    def withdraw(self,amount):
        self.Balance = self.Balance - amount

    def deposit(self,amount):
        self.Balance = self.Balance + amount

    def checkbalance(self):
        print("My balance is:",self.Balance)

obj1 = BankAccount("12345678","Aditya","SBIN00100",10000)
obj1.display()
print()
obj1.withdraw(2000)
obj1.checkbalance()

obj1.deposit(25000)
obj1.checkbalance()

obj1.deposit(25000)
obj1.checkbalance()

obj1.withdraw(9000)
obj1.checkbalance()

obj1.withdraw(1)
obj1.checkbalance()
