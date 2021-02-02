#include <iostream>
#include <queue>
#include <stack>

#include "src/Node.h"

using namespace std;

bool verificar(Node* teste, queue<Node> open, queue<Node> closed)
{

    queue<Node> newOpen;
    queue<Node> newClosed;

    newOpen = open;
    newClosed = closed;

    bool lenght = newClosed.empty();

    while(lenght != 1){

        Node* comparar1 = new Node(5);
        *comparar1 = newClosed.front();

        Node* comparar2 = new Node(5);
        comparar2 = teste;
        
        if(comparar1 == comparar2)
            return false;
        newClosed.pop();
        lenght = newClosed.empty();
    }
    lenght = newOpen.empty();
    while(lenght != 1){

        Node* comparar1 = new Node(5);
        *comparar1 = newOpen.front();

        Node* comparar2 = new Node(5);
        comparar2 = teste;
       
        if(comparar1 == comparar2)
            return false;

        newOpen.pop();
        lenght = newOpen.empty();
    }
    return true;
}

bool executar(Node* execute, queue<Node>& open, queue<Node>& closed)
{
    for(int i = 0; i < 6; i++)
    {
        Node* son = new Node(5);
        *son = *execute;
        if(i == 0){
            bool test = son->move1to2();
            bool exist = verificar(son, open, closed);
            if(test == true && exist == true){
                son->setFather(execute);
                open.push(*son);
                //son->printTowers();
            }
        }
        else if(i == 1){
            bool test = son->move1to3();
            bool exist = verificar(son, open, closed);
            if(test == true && exist == true){
                son->setFather(execute);
                open.push(*son);
                //son->printTowers();
            }
        }
        else if(i == 2){
            bool test = son->move2to1();
            bool exist = verificar(son, open, closed);
            if(test == true && exist == true){
                son->setFather(execute);
                open.push(*son);
                //son->printTowers();
            }
        }
        else if(i == 3){
            bool test = son->move2to3();
            bool exist = verificar(son, open, closed);
            if(test == true && exist == true){
                son->setFather(execute);
                open.push(*son);
                //son->printTowers();
            }
        }
        else if(i == 4){
            bool test = son->move3to1();
            bool exist = verificar(son, open, closed);
            if(test == true && exist == true){
                son->setFather(execute);
                open.push(*son);
                //son->printTowers();
            }
        }
        else{
            bool test = son->move3to2();
            bool exist = verificar(son, open, closed);
            if(test == true && exist == true){
                son->setFather(execute);
                open.push(*son);
                //son->printTowers();
            }
        }
        stack<int> t1 = son->getT1();
        stack<int> t2 = son->getT2();
        if(t1.empty() && t2.empty())
        {
            cout << "Solucao encontrada:" << endl;
            son->printTowers();
            return 1;
        }
    }
    return 0;
}

int main(){

    int* nivel;
    *nivel = 0;
    Node* start = new Node(5);
    start->printTowers();

    queue<Node> open;
    queue<Node> closed;

    open.push(*start);

    // Execução
    while(!open.empty()){
        cout << endl<< "Nova:"<< endl;
        bool teste = executar(start, open, closed);
        if(teste == true){
            return 0;
        }
        else{
            closed.push(*start);
            open.pop();
            *start = open.front();
        }
    }
    return 0;
}