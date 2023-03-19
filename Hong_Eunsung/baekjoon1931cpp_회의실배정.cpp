#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct meetTime {
	int start;
	int end;
};

bool compare(meetTime a, meetTime b) {
	if (a.end == b.end)
		return a.start < b.start;
	else
		return a.end < b.end;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, temp, max = 0, latest = 0;
	cin >> n;
	vector<meetTime> meet(n);
	for (int i = 0; i < n; i++) {
		cin >> meet[i].start >> meet[i].end;
	}


	//test code
	cout << "meet : \n";
	for (int i = 0; i < n; i++) {
		cout << "(" << meet[i].start << ", " << meet[i].end << "), ";
	}
	cout << "\n";


	sort(meet.begin(), meet.end(), compare);
	latest = meet.back().end;
	vector<int>dp(latest+1, 0);


	//test code
	cout << "meet : \n";
	for (int i = 0; i < n; i++) {
		cout << "(" << meet[i].start << ", " << meet[i].end << "), ";
	}
	cout << "\n";


	//dp[0]�� ���� ����
	dp[0] = 0;
	temp = 0;
	while (meet[temp].end == 0) {
		dp[0]++;
		temp++;
	}

	int j = 1; //dp ��ȣ
	for (int i = temp; i < n; i++) { //i�� ���� meet�� �տ������� Ž��
		//test code
		cout << "i : " << i << "\n";

		while (j < meet[i].end) {//�������� �˻��� meet�� ����ð��� ���� dp��ȣ���� ũ�ٸ�
			dp[j+1] = dp[j];
			j++;
		}

		//test code
		cout << "dp[meet[" << i << "].start : " << dp[meet[i].start] << "\n";

		temp = dp[meet[i].start] + 1;
		dp[j] = dp[j-1] < temp ? temp : dp[j-1];
		max = dp[j] > max ? dp[j] : max;
		
		//test code
		cout << "temp is : " << temp << " and " << "new dp[" << j << "] : " << dp[j] << "\n";
	}
	cout << max;
}