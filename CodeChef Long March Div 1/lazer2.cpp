// A C++ program to demonstrate operations of KD tree 
#include<bits/stdc++.h> 
using namespace std; 
#define ll long int
const int k = 2; 

// A structure to represent node of kd tree 
struct Node 
{ 
	int point[k]; // To store k dimensional point 
	Node *left, *right; 
}; 

// A method to create a node of K D tree 
struct Node* newNode(int arr[]) 
{ 
	struct Node* temp = new Node; 

	for (int i=0; i<3; i++) 
	temp->point[i] = arr[i]; 

	temp->left = temp->right = NULL; 
	return temp; 
} 

// Inserts a new node and returns root of modified tree 
// The parameter depth is used to decide axis of comparison 
Node *insertRec(Node *root, int point[], unsigned depth) 
{ 
	// Tree is empty? 
	if (root == NULL) 
	return newNode(point); 

	// Calculate current dimension (cd) of comparison 
	unsigned cd = depth % k; 

	// Compare the new point with root on current dimension 'cd' 
	// and decide the left or right subtree 
	if (point[cd] < (root->point[cd])) 
		root->left = insertRec(root->left, point, depth + 1); 
	else
		root->right = insertRec(root->right, point, depth + 1); 

	return root; 
} 

// Function to insert a new point with given point in 
// KD Tree and return new root. It mainly uses above recursive 
// function "insertRec()" 
Node* insert(Node *root, int point[]) 
{ 
	return insertRec(root, point, 0); 
} 

// A utility method to determine if two Points are same 
// in K Dimensional space 
int condition(int point1[], int point2[]) 
{ 
	// Compare individual pointinate values 
	/*for (int i = 0; i < k; ++i) 
		if (point1[i] != point2[i]) 
			return false; 

	return true; */
	if(point1[0]!=point2[0]) return 0;
	int fir=point1[1];
	int sec=point1[2];
	int y=point2[1];
	if(sec>=y && y>fir) return 1;
	else if(sec<=y && fir>y) return 1;
	else if(fir==y && sec!=y) return 1;
	else if(fir==y && sec==y) return 2;
	return 0;
} 

// Searches a Point represented by "point[]" in the K D tree. 
// The parameter depth is used to determine current axis. 
bool searchRec(Node* root, int point[], unsigned depth) 
{ 
	// Base cases 
	if (root == NULL) 
		return false; 
	int a=condition(root->point, point);
	if (a!=0)
		return a; 

	// Current dimension is computed using current depth and total 
	// dimensions (k) 
	unsigned cd = depth % k; 

	// Compare point with root with respect to cd (Current dimension) 
	if (point[cd] < root->point[cd]) 
		return searchRec(root->left, point, depth + 1); 

	return searchRec(root->right, point, depth + 1); 
} 

// Searches a Point in the K D tree. It mainly uses 
// searchRec() 
int search(Node* root, int x1,int x2,int y) 
{ 
	ll ans=0;
	// Pass current depth as 0 
	for(int i=x1;i<x2;i++){
		int point[]={i,y};
		if(searchRec(root, point, 0)) ans++; 
	}
	return ans;
} 

// Driver program to test above functions 
/*int main() 
{ 
	struct Node *root = NULL; 
	int points[][k] = {{3, 6}, {17, 15}, {13, 15}, {6, 12}, 
					{9, 1}, {2, 7}, {10, 19}}; 

	int n = sizeof(points)/sizeof(points[0]); 

	for (int i=0; i<n; i++) 
	root = insert(root, points[i]); 

	int point1[] = {10, 19}; 
	(search(root, point1))? cout << "Found\n": cout << "Not Found\n"; 

	int point2[] = {12, 19}; 
	(search(root, point2))? cout << "Found\n": cout << "Not Found\n"; 

	return 0; 
} */


// Driver program to test above functions 
int main() 
{ 
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		int points[n-1][k];
		int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		for(int i=0;i<n-1;i++){
			points[i][0]=i;
			points[i][1]=arr[i];
			points[i][2]=arr[i+1];
		}
		struct Node* root = NULL; 
		for (int i = 0; i < n-1; i++) 
			root = insert(root, points[i]); 

		while(q--){
			int x1,x2,y;
			cin>>x1>>x2>>y;
			x1--;
			x2--;
			cout<<search(root,x1,x2,y)<<"\n";
		}
	}
	return 0; 
} 
