#include <bits/stdc++.h>
using namespace std;

struct Field {
	vector<int> links;
	int blob = -1;
};

vector<Field> fields;
vector<int> homeFields;
vector<int> goalFields;

void dfs(int fieldNum, int blob) {
	Field& field = fields.at(fieldNum);
	field.blob = blob;
	if (blob == 0) homeFields.push_back(fieldNum);
	if (blob == 1) goalFields.push_back(fieldNum);
	for (int link : field.links) {
		if (fields[link].blob == -1) {
			dfs(link, blob);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	//freopen("in1.in", "r", stdin);
	int t; cin >> t;
	for (int round=0; round<t; round++) {
		int n, m;
		cin >> n >> m;
		fields.clear();
		fields.resize(n+1);
		
		homeFields.clear();
		goalFields.clear();
		
		for (int i=0; i<m; i++) {
			int a, b; cin >> a >> b;
			fields[a].links.push_back(b);
			fields[b].links.push_back(a);
		}
		
		
		dfs(1, 0); // 0 is blob ID of home fields
		dfs(n, 1); // 1 is blob ID of goal fields
		int id = 2;
		for (int i=2; i<n; i++) {
			if (fields[i].blob == -1) {
				dfs(i, id);
				id++;
			}
		}
		sort(homeFields.begin(), homeFields.end());
		sort(goalFields.begin(), goalFields.end());
		vector<long long> costForBlob(id, LLONG_MAX);
		
		
		int homeI = 0;
		
		int field = 1;
		while (field <= n) {
			
			if (homeI + 1 < (int) homeFields.size() and abs(field - homeFields.at(homeI)) >= abs(field - homeFields.at(homeI+1))) {
				homeI++;
			} else {
				int blob = fields.at(field).blob;
				long long cost = pow(abs(field - homeFields.at(homeI)), 2);
				assert(blob >= 0);
				assert((size_t)blob < costForBlob.size());
				costForBlob[blob] = min(costForBlob.at(blob), cost);
				field++;
			}
		}
		
		long long minCost = LLONG_MAX;
		int goalI = 0;
		field = 1;
		
		while (field <= n) {
			
			if (goalI + 1 < (int) goalFields.size() and abs(field - goalFields.at(goalI)) >= abs(field - goalFields.at(goalI+1))) {
				goalI++;
			} else {
				int blob = fields.at(field).blob;
				long long cost = pow(abs(field - goalFields.at(goalI)), 2);
				minCost = min(minCost, costForBlob.at(blob) + cost);
				field++;
			}
		}
		cout << minCost << endl;
		
	}
	
	
	return 0;
}
