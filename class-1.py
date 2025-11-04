class student:
  def _init_(self,name,rollno,marks):
   self.name = name
   self.rollno = rollno
   self.marks =marks

  def display(self):
    print("My name is:",self.name)
    print("My Rollno is:",self.rollno)
    print("My marks are",self.marks)

    s1= student("aditya","24B1DS036",72)
    s1.display()
    print()

    s2= student("sai","24B1DS037",85)
    s2.display()