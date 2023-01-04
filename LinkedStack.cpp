// #include "FileStream.cpp"
// #include <iostream>
// using namespace std;

// struct Node
// {
//     int data;
//     Node *next;
// };

// class LinkedStack
// {
//     private :
        
//         Node *top;

//     public :

//         LinkedStack()
//         {
//             top = nullptr;
//             FileStream::Write("stack constructed\n");
//         }

//         bool empty()
//         {
//             if(top == nullptr)
//             {   
//                 return true;
//             }
//             else
//             {
//                 return false;
//             }
//         }

//         void push(int x)
//         {
//             Node* temp;
//             temp = new Node;
//             temp->data = x;

//             if(top == nullptr)
//             {
//                 top = temp;
//                 top->next = nullptr; 

//                 FileStream::Write("stack added " + to_string(x) + "\n");
//                 //cout<<"Stack added "<<x<<endl;//print the pushed number (for reference)
//             }
//             else
//             {
//                 temp->next = top;
//                 top = temp;

//                 FileStream::Write("stack added " + to_string(x) + "\n");
//                 //cout<<"Stack added "<<x<<endl;//print the pushed number (for reference)
//             }
//         }

//         int pop()
//         {
//             int x;
//             Node *temp;

//             if(!empty())
//             {
//                 x = top->data;
//                 temp = top;
//                 top = top->next;
//                 delete temp;

//                 FileStream::Write("stack deleted " + to_string(x) + "\n");
//                 //cout<<"Stack deleted "<<x<<endl;//print the poped number (for reference)

//                 return x;
//             }
//             else
//             {
//                 FileStream::Write("stack is empty!!\n");
//                 exit(0);
//             }
//         }

//         void print()
//         {
//             while(top != nullptr)
//             {
//                 //cout<<top->data<<" ";
//                 FileStream::Write(to_string(top->data) + " ");

//                 top = top->next;
//             }

//             FileStream::Write("\n");
//         }
// };


// // int main()
// // {
// //     LinkedStack ls;

// //     cout<<"Stack constructed"<<endl;

// //     ls.push(10);
// //     ls.push(20);
// //     ls.push(100);
// //     ls.push(50);

// //     ls.pop();

// //     ls.print();
// // }