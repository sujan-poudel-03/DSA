package Java.linkedlist;

public class SinglyLinkedListEmployeeManagement {
    public static Employee createEmployeeNode(String name, int id) {
        Employee employee = new Employee(name, id);

        employee.setNext(null);

        return employee;
    }

    public static Employee insertEmployeeAtBeginning(Employee head, String name, int id) {
        Employee newEmployee = createEmployeeNode(name, id);

        newEmployee.setNext(head);

        return newEmployee;
    }

    public static Employee insertEmployeeAtEnd(Employee head, String name, int id) {
        Employee newEmployee = createEmployeeNode(name, id);

        if (head == null) {
            head = newEmployee;
        } else {
            Employee current = head;

            while (current.next != null) {
                current = current.next;
            }

            current.next = newEmployee;
        }

        return head;
    }

    public static void updateEmployee(Employee head, int id, String newName) {
        Employee current = head;

        while (current != null) {
            if (current.id == id) {
                current.name = newName;
                System.out.println("Employee with Id " + id + " has been updated with a new name: " + newName);
                return;
            }
            current = current.next;
        }

        System.out.println("No employee found with ID " + id);
    }

    public static Employee deleteEmployee(Employee head, int id) {
        if (head == null) {
            System.out.println("No employees in the list");
            return head;
        }

        if (head.id == id) {
            head = head.next;
            System.out.println("Employee with id " + id + " has been deleted");

            return head;
        }

        Employee current = head;

        while (current.next != null) {
            if (current.next.id == id) {
                Employee temp = current.next;
                current.next = temp.next;
                System.out.println("Employee with id " + id + " has been deleted");
                return head;
            }

            current = current.next;
        }

        System.out.println("No employee found with id " + id);
        return head;
    }

    public static void displayEmployees(Employee head) {
        if (head == null) {
            System.out.println("No employees in the list");
        } else {
            Employee current = head;
            while (current != null) {
                System.out.println("Employee name: " + current.name + " ID: " + current.id);
                current = current.next;
            }
        }
    }

    public static void main(String[] args) {
        Employee employeeList = null;
        employeeList = insertEmployeeAtBeginning(employeeList, "John Doe", 101);
        employeeList = insertEmployeeAtEnd(employeeList, "Jane Smith", 102);
        employeeList = insertEmployeeAtEnd(employeeList, "Mike Johnson", 103);
        displayEmployees(employeeList);

        updateEmployee(employeeList, 102, "Jane Miller");
        displayEmployees(employeeList);

        employeeList = deleteEmployee(employeeList, 101);
        displayEmployees(employeeList);
    }
}

class Employee {
    String name;
    int id;
    Employee next;

    public Employee(String name, int id) {
        this.name = name;
        this.id = id;
    }

    public void setNext(Employee employeeNode) {
        this.next = employeeNode;
    }
}