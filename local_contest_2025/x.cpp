#include <bits/stdc++.h>
using namespace std;
// Program X

vector<long long> heights;

// void recalculate(int node) {
//     //calculate the solution for the current segment,
//     //considering the sons are correctly solved
//     segm_tree[node] = min(segm_tree[2 * node + 1], segm_tree[2 * node + 2]);
// }

// void build(int node, int left, int right) { //"node" is the index in the array, while "left"
//                                             // and "right" are the ends of the current segment
//     if (left == right) {
//         segm_tree[node] = heights[left]; //we are in a leaf node
//     } else {
//         int middle = (left + right) / 2;
//         build(2 * node + 1, left, middle);
//         build(2 * node + 2, middle + 1, right);
//         recalculate(node);
//     }
// }


// int64_t query(int node, int left, int right, int x, int y) {
//     if (x <= left && right <= y) {
//         //the segment of "node" is completely included in the query
//         return segm_tree[node];
//     } else {
//         int64_t answer = std::numeric_limits<uint64_t>::max();
//         int middle = (left + right) / 2;
//         if (x <= middle) {
//             //the query segment and the left son segment have at least one element in common
//             answer = min(answer, query(2 * node + 1, left, middle, x, y));
//         }
//         if (y >= middle + 1) {
//             //the query segment and the right son segment have at least one element in common
//             answer = min(answer, query(2 * node + 2, middle + 1, right, x, y));
//         }
//         //we would not have entered this function if (x, y) and (left, right) had nothing in common,
//         //so there is no risk of answer returning -Infinity here, as either the left or the right son
//         //would update it
//         return answer;
//     }
// }

// A utility function to get the minimum of two numbers  
long long minVal(long long x, long long y) { return (x < y) ? x : y; }

// A utility function to get the middle index from corner indexes.  
long long getMid(long long s, long long e) { return s + (e - s) / 2; }

// A recursive function to get the minimum value in a given range of array indexes. 
// The following are parameters for this function.
//     st --> Pointer to segment tree  
//     index --> Index of current node in the segment tree. Initially 0 is passed as root is always at index 0  
//     ss & se --> Starting and ending indexes of the segment represented by current node, i.e., st[index]  
//     qs & qe --> Starting and ending indexes of query range
long long RMQUtil(vector<long long>& st, long long ss, long long se, long long qs, long long qe, long long index)  
{  
    // If segment of this node is a part of the given range, return the min of the segment  
    if (qs <= ss && qe >= se)  
        return st[index];  
  
    // If segment of this node is outside the given range  
    if (se < qs || ss > qe)  
        return LLONG_MAX;  
  
    // If a part of this segment overlaps with the given range  
    long long mid = getMid(ss, se);  
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),  
                  RMQUtil(st, mid+1, se, qs, qe, 2*index+2));  
}  
  
// Return minimum of elements in range from index qs (query start) to qe (query end). 
// It mainly uses RMQUtil()  
long long RMQ(vector<long long>& st, long long n, long long qs, long long qe)  
{  
    // Check for erroneous input values  
    if (qs < 0 || qe > n-1 || qs > qe)  
    {  
        cout << "Invalid Input";  
        return -1;  
    }  
  
    return RMQUtil(st, 0, n-1, qs, qe, 0);  
}  
  
// A recursive function that constructs Segment Tree for arr[ss..se]. 
// si is index of current node in segment tree st  
long long constructSTUtil(vector<long long>& arr, long long ss, long long se, vector<long long>& st, long long si)  
{  
    // If there is one element in array, store it in current node of segment tree and return  
    if (ss == se)  
    {  
        st[si] = arr[ss];  
        return arr[ss];  
    }  
  
    // If there are more than one elements, recur for left and right subtrees 
    // and store the minimum of two values in this node  
    long long mid = getMid(ss, se);  
    st[si] = minVal(constructSTUtil(arr, ss, mid, st, si*2+1),  
                    constructSTUtil(arr, mid+1, se, st, si*2+2));  
    return st[si];  
}  
  
/* Function to construct segment tree from given array. 
This function allocates memory for segment tree and calls constructSTUtil() to fill the allocated memory */
vector<long long> constructST(vector<long long>& arr, long long n)  
{  
    // Height of segment tree  
    long long x = (long long)(ceil(log2(n)));  
  
    // Maximum size of segment tree  
    long long max_size = 2 * (long long)pow(2, x) - 1;  
  
    vector<long long> st(max_size);  
  
    // Fill the allocated memory st  
    constructSTUtil(arr, 0, n-1, st, 0);  
  
    // Return the constructed segment tree  
    return st;  
}  



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inputs/x1.in", "r", stdin);

    int64_t n, q; cin >> n >> q;

    heights.resize(n + 1);

    for (int i = 1; i < n+1; i++) {
        int64_t input; cin >> input;

        heights[i] = heights[i - 1] + input;
    }
    // heights.push_back(1);

    vector<long long> st = constructST(heights, n + 1);  

    for (int i = 0; i < q; i++) {
        long long l, r; cin >> l >> r;

        long long lowest_height = RMQ(st, n + 1, l, r);

        if (heights[l] == heights[r] && lowest_height == heights[l]) {
            cout << "MAYBE\n";
        } else {
            cout << "NO\n";
        }
    }


    // cout << "Heights array: \n";

    // for (int i = 0; i <= n; i++) {
    //     cout << heights[i] << ' ';
    // }
    // cout << endl;

    // for (int i = 0; i <= n; i++) {
    //     cout << i << " " << n << " " << RMQ(st, n + 1, i, n) << "\n";
    // }
}