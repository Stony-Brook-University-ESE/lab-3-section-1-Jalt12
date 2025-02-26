#include <iostream>

class node{
public:
    std::string title;
    std::string author;
    int year;
    node*next;
    node();
    node(std::string t,std::string a,int y);
};

node::node()
{
    year = 0;
    next = NULL;
}

node::node(std::string t,std::string a,int y)
{
    this -> title = t;
    this -> author = a;
    this -> year = y;
    this -> next = NULL;
}

class list{
private:
    node *head;
public:
    list();
    void addtitle(std::string t, std::string a, int y);
    void removetitle(std::string t);
    void print();
};

list::list()
{
    head = NULL;
}

void list::addtitle(std::string t, std::string a, int y)
{
    node *new_node = new node(t, a, y);

    if (head == NULL) {
        head = new_node;
        return;
    }

    else{
        if(new_node->title < head->title){
            new_node->next = this->head;
            this->head = new_node;
        }
        else{
            node *p1 = head;
            node *p2 = p1->next;
            while(p2 !=NULL && new_node->title >= p2->title){
                p1 = p2;
                p2 = p2->next;
            }
            p1->next = new_node;
            new_node->next = p2;
        }
    }
}

void list::removetitle(std::string t)
{
    if (head == NULL) {
        std::cout << "List is empty";
    }

    else{
        if(t == head->title){
            node*old = head;
            head = head->next;
            delete old;
        }
        else{
            node *p1 = head;
            node *p2 = p1->next;
            while(p2 !=NULL && t > p2->title){
                p1 = p2;
                p2 = p2->next;
            }
            if(p2 != NULL && t == p2->title){
                p1->next = p2->next;
                delete p2;
            }
            else{
                std::cout << "Song is not in list.";
            }
        }
    }
}

void list::print() {
    node *temp = head;
    int i=1;

    if (head == NULL) {
        std::cout << "List empty" << std::endl;
        return;
    }

    else{
        while(temp != NULL){
            std::cout << temp->title << "\n";
            temp = temp->next;
        }
    }
}

int main(){
    list list;

    list.addtitle("song1", "author1", 1901);
    list.addtitle("song4", "author4", 1904);
    list.addtitle("song2", "author2", 1902);
    list.addtitle("song3", "author3", 1903);

    list.removetitle("song3");

    list.print();
}
