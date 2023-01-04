// #include "FileStream.cpp"
// #include <exception>

// struct Node
// {
//     int32_t data;
//     Node* next;
// };

// class SortedLinkedList{
// private:
//     Node* head;

// public:
//     SortedLinkedList()
//     {
//         head = nullptr;
//         FileStream::Write("sortedList constructed\n");
//     }

//     ~SortedLinkedList()
//     {
//         delete head;
//         head = nullptr;
//     }

//     void Add(int32_t data)
//     {
//         Node* newNode = (Node*)malloc(sizeof(Node));
//         newNode->data = data;

//         Node* current = head;
//         Node* prev = nullptr;
//         while (current!=nullptr && current->data < data) {
//           prev = current;
//           current = current->next;
//         }

//         newNode->next = current;
//         if (prev) {
//           prev->next = newNode;
//         } else {
//           head = newNode;
//         }
//         FileStream::Write("sortedList added " + std::to_string(data) + "\n");
//     }


//     void Delete(int32_t data)
//     {
//         if(check_empty()){
//             FileStream::Write("sortedList is empty\n");
//             throw "sortedList is empty";
//         }
//         Node* temp = head;
//         Node* prev = nullptr;
//         while(temp != nullptr && temp->data != data){
//             prev = temp;
//             temp = temp->next;
//         }
//         if(temp == nullptr){
//             FileStream::Write("data not found\n");
//         }else{
//             if(prev == nullptr){
//                 head = head->next;
//             }else{
//                 prev->next = temp->next;
//             }
//             delete temp;
//             FileStream::Write("sortedList deleted " + std::to_string(data) + "\n");
//         }

//     }

//     void Print()
//     {
//         for (Node* tempNode = head; tempNode != nullptr; tempNode = tempNode->next){
//             FileStream::Write(std::to_string(tempNode->data) + " ");
//         }
//         FileStream::Write("\n");
//     }
//     bool check_empty(){
//         return head == nullptr;
//     }
// };
