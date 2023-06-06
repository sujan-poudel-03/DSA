import java.util.ArrayList;

public class TodoList {
    public static int MAX_SIZE = 100;
    public static ArrayList<Todo> tasks = new ArrayList<>();

    public static void main(String[] args) {
        initList();

        addTask("Buy groceries", false);
        addTask("Pay bills", true);
        addTask("Do laundry", false);

        displayTasks();
    }

    public static void initList() {
        tasks.clear();
    }

    public static void addTask(String task, boolean done) {
        if (tasks.size() == MAX_SIZE) {
            System.out.println("List is full, cannot add more tasks!");
            return;
        }
        
        Todo todo = new Todo(task);

        todo.setDone(done);

        tasks.add(todo);
    }

    public static void displayTasks() {
        if (tasks.size() == 0) {
            System.out.println("No tasks in the list!");
            return;
        }

        System.out.println("=====Tasks=====");

        for(Todo task : tasks) {
            System.out.println("Task: " + task.task + " | Done: " + task.done);
        }
    }
}


class Todo {
    public String task;
    public boolean done = false;

    public Todo(String name) {
        this.task = name;
    }

    public void setDone(boolean newStatus) {
        done = newStatus;
    }
}