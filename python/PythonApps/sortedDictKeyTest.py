from operator import itemgetter, attrgetter

class Student:
    def __init__(self, name, grade, age):
        self.name = name;
        self.grade = grade;
        self.age = age;
    def __repr__(self):
        # note: since repr accepts only one argument and the intention here
        # is to display the elements of self as a tuple, make sure to 
        # use two ()s, NOT one.
        return repr((self.name, self.grade, self.age))
    
sList = [
          Student('John', 'B', 15),
          Student('john', 'A', 15),
          Student('eliot', 'A', 15),
          Student('mary', 'B', 12),
          Student('eliot', 'C', 10),
          Student('mary', 'A', 15),
          Student('eliot', 'A', 10),
          Student('mary', 'A', 12),
        ]
# class Student:
#     def __init__(self, name, grade, age):
#         self.name = name
#         self.grade = grade
#         self.age = age
#     def __repr__(self):
#         return repr((self.name, self.grade, self.age))

# student_objects = [Student('john', 'A', 15), Student('jane', 'B', 12), Student('dave', 'B', 10),]
# sorted(student_objects, key=lambda student: student.age)   # sort by age

if __name__ == '__main__':
    
    ######## Sample for a list of tuples #########

    tup = [('Michael', 'A', 45), ('henry', 'B', 60), ('james', 'A', 22)]
    
    # print(sorted(tup, key=lambda t: t[2]))
    # print(sorted(tup, key=lambda t: t[1]))
    # print(sorted(tup, key=lambda t: t[0]))
    # print(sorted(tup, key=lambda t: t[0].upper()))
    # print(sorted(tup, key=lambda t: t[1].lower()+t[0].upper()))

    # instead of lambda, itemgetter from operator module can be used!!!
    print(sorted(tup, key=itemgetter(2)))

    ######## Sample for a list of instance objects of a class #########

    #sortedSlist = (sorted(sList, key=lambda s: s.age))
    #for s in sortedSlist:
    #    print(s)            # display item is each object's items
    #print(sortedSlist)      # display item is a list of 3 objects
    print(sorted(sList, key=attrgetter("name")))
    print(sorted(sList, key=attrgetter("grade")))
    print(sorted(sList, key=attrgetter("age")))
    # Multiple levels of sorting also works!
    print(sorted(sList, key=attrgetter("name", "age", "grade")))

    # Here the following can't be done because attrgetter() doesn't have 
    # lower() function
    # print(sorted(sList, key=attrgetter("name").lower()))
    # Instead, use the lambda function - 
    print(sorted(sList, key=lambda s:s.name))
    # It works with lower(), upper(), etc.
    print(sorted(sList, key=lambda s:s.name.lower()))
    #print(sorted(sList, key=lambda s:s[s.name]))
    
    print('Done')