// #include "LinkedList.cpp"

// using namespace std;

// class BinarySearchTree
// {
//     private:
//         struct tree
//         {
//             int data;
//             tree *left;
//             tree *right;
//         };

//         tree* root;

//     public:
//         BinarySearchTree()
//         {
//             cout<<"bst constructed\n";
//             root = nullptr;
//         }
//         tree* addNode(int number){
//             tree* newNode = new tree;
//             newNode->data = number;
//             newNode->right = newNode->left = nullptr;
//             return newNode;
//         }
//         bool treeEmpty()
//         {
//             return root == nullptr;
//         }
//         void addValue(int val)
//         {
//             root = insertNode(root,val);
//         }

//       tree* insertNode(tree* node,int val)
//       {
//             if (node == nullptr)
//             {
//                 node = addNode(val);
//                 cout << " bst added" << val << endl;
//             }

//             else if (val <= node->data)
//             {
//                 node->left = insertNode(node->left, val);
//             }

//             else
//             {
//                 node->right = insertNode(node->right, val);
//             }
//             return node;
//       }


//         void deleteRoot(int datas)
//         {
//             root = deleteNode(root,datas);
//         }
//         tree* deleteNode(tree *roots, int dataS)
//         {
//             if(roots == nullptr)
//             {
//                 return roots;
//             }
//             else if(dataS < roots->data)
//             {
//                 roots->left = deleteNode(roots->left,dataS);
//             }
//             else if(dataS > roots->data)
//             {
//                 roots->right = deleteNode(roots->right,dataS);
//             }
//             else
//             {
//                 if(roots->left == nullptr && roots->right == nullptr)
//                 {
//                     delete roots;
//                     return roots = nullptr;
//                 }
//                 else if(roots->left == nullptr)
//                 {
//                     tree *temp = roots;
//                     roots = roots->right;
//                     delete temp;
//                 }
//                 else if(roots->right == nullptr)
//                 {
//                     tree *temp = roots;
//                     roots = roots->left;
//                     delete temp;
//                 }
//                 else
//                 {
//                     tree* temp = findMax(roots->right);
//                     roots->data = temp->data;
//                     roots->right = deleteNode(roots->right,temp->data);
//                 }
//             }
//             return roots;
//         }
//         tree* findMax (tree *root)
//         {
//           while (root->right)
//             {
//                 root = root->right;
//             }
//           return root;
//         }
//         void inorder(tree* n)
//         {
//             if( !n )
//                 return;
//             inorder( n->left );
//             cout<<n->data<<" : ";
//             inorder( n->right);

//         }
//         void callInorder()
//         {
//             inorder(root);
//         }
// };

// // int main()
// // {
// //     BinarySearchTree bt;
// //     bt.addValue(30);
// //     bt.addValue(50);
// //     bt.addValue(20);
// //     bt.addValue(10);
// //     bt.deleteRoot(30);

// //     cout<<bt.treeEmpty()<<endl;
// //     bt.callInorder();
// // }
