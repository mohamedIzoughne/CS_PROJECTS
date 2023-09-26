#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Todo_item {
public:
    string description;
    int status;
    Todo_item *next;

    Todo_item (string value)
    {
        description = value;
    }
};

class Todo_list {
private:
    Todo_item *first_item;
    int notes_number;
public:
    Todo_list() {
        first_item = nullptr;
    }

    void add_new_item(string desc)
    {
        Todo_item *new_item = new Todo_item(desc);
        new_item->status = 0;
        if (first_item == nullptr)
        {
            first_item = new_item;
            first_item->next = nullptr;
            return;
        }

        new_item->next = first_item;
        first_item = new_item;
    }

    void mark_as_completed(string desc)
    {
        Todo_item *temp = first_item;
        while(temp != nullptr)
        {
            if (temp->description == desc)
            {
                temp->status = 1;
                temp = temp->next;
                continue;
            }
            temp = temp->next;
        }
    }

    void delete_completed()
    {
        Todo_item *temp = first_item;

        while(temp != nullptr)
        {
            Todo_item *current = temp->next;
//            cout << current->description;
//            cout << temp->description << "\n";
            if (temp == first_item && temp->status == 1)
            {
                Todo_item *next_element = temp->next;
                delete temp;
                temp = next_element;
                first_item = next_element;
                continue;
            }
            // ---------
            if (current != nullptr)
            {
                Todo_item *next_element = current->next;
                cout << "\n deleted: " << current->description;
            if (current->status == 1)
            {
                delete current;
            }
                temp->next = next_element;
            }
            // -----------
            temp = temp->next;
        }
    }

    void clear_todo_list()
    {
        Todo_item *temp = first_item;
        while(temp != nullptr)
        {
            Todo_item *next = temp->next;
            delete temp;
            temp = next;
        }
        first_item = nullptr;
    }

//    void remove_completed()
//    {
//        Todo_item *previous = nullptr;
//        Todo_item *current = first_item;
//
//        while(temp != nullptr)
//        {
//            Todo_item *current = temp->next;
////            cout << current->description;
////            cout << temp->description << "\n";
//            if (temp == first_item && temp->status == 1)
//            {
//                Todo_item *next_element = temp->next;
//                delete temp;
//                temp = next_element;
//                first_item = next_element;
//                continue;
//            }
//            // ---------
//            if (current != nullptr)
//            {
//                Todo_item *next_element = current->next;
//                cout << "\n deleted: " << current->description;
//            if (current->status == 1)
//            {
//                delete current;
//            }
//                temp->next = next_element;
//            }
//        }


    void remove_completed()
    {
         Todo_item *previous = nullptr;
        Todo_item *current = first_item;
        while(current != nullptr)
        {
            if (current->status == 1)
            {
                if (previous == nullptr)
                {
                    first_item = current->next;
                    delete current;
                    current = first_item;
                } else
                {
                    previous->next = current->next;
                    delete current;
                    current = previous->next;
                }
            } else
            {
                previous = current;
                current = current->next;
            }
        }
    }

    void display_todos()
    {
        Todo_item *temp = first_item;
        while(temp != nullptr)
        {
            cout << temp->description << endl;
            temp = temp->next;
        }
    }
};


int main()
{
    Todo_list tasks;

    tasks.add_new_item("1");
    tasks.add_new_item("2");
    tasks.add_new_item("3");
    tasks.add_new_item("4");
    tasks.add_new_item("5");
//
        tasks.mark_as_completed("4");
    tasks.mark_as_completed("5");
//        tasks.mark_as_completed("3");
    tasks.mark_as_completed("2");
    tasks.mark_as_completed("1");


    tasks.remove_completed();
    tasks.display_todos();
    return 0;
}
