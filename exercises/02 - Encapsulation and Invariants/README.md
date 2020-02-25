# Encapsulation and Class Invariants

## Cliffnotes

- P.O.D
- Invariants (assert?)
- Encapsulation (public vs private)
- class keyword
- Member functions (hidden *this* pointer, const qualifier)
- Constructors (default, order, initializer list)

## Notes

WIP

## Small Problem

Implement the following classes

### Employee

The employees have the following properties

- Name with no more than 50 characters
- Age between 18 and 64
- Monthly salary between 610 and 10000
- Relevant constructors, selectors and mutators
- A method that prints all information about the employee

### Company

With the following properties

- Up to 1000 employees
- Relevant constructors, selectors and mutators
- A method that checks if the company is empty
- A method that adds an employee to the company
- A method that fires an employee with given name from the company and returns false if he doesn't exist (remove only first one with given name)
- A method that sorts the employees in the company by name
- A method that gives the total monthly salary of all employees
- A method that raises the salary of all employees by a given percantage
- A method that prints the information about all employees