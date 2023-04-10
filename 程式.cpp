# include <iostream>
# include <vector>
# include <fstream>
using namespace std;

struct Info {
	string formula;
	int ans;
	bool divisible;
}; // struct Info

string s = "ans.txt";
fstream fout(s.c_str(), fstream::out);

void Calculate(vector<int> allOfNum, vector<Info> &allOfAns, int sum, int level, string formula);
string IntToString(int num);
bool CheckDivisible(vector<Info> &allOfAns, int K);
void PrintStar();

int main() {
	int M, N, K, temp;
	vector<int> allOfNum;
	vector<Info> allOfAns;
	cout << "Input M : ";
	cin >> M;
	
	
	for ( int a = 0 ; a < M ; a++ ) { // Mission Start
		allOfNum.clear();
		allOfAns.clear();
		cout << "Input N, K : ";
		cin >> N >> K;
		cout << "Input " << N << " Number : ";
		
		for ( int b = 0 ; b < N ; b++ ) { // Input Number
			cin >> temp;
			allOfNum.push_back(temp);
		} // for(b)
		
		Calculate(allOfNum, allOfAns, allOfNum[0], 1, IntToString(allOfNum[0]));
		fout << "\n";
		PrintStar();
		
		
		
		if ( CheckDivisible(allOfAns, K) ) fout << "Divisible\n";
		else fout << "Not divisible\n";
		
		for ( int b = 0 ; b < allOfAns.size() ; b++ ) {
		  if ( allOfAns[b].divisible ) fout << "* ";
		  else fout << "  ";

		  fout << allOfAns[b].formula << " = " << allOfAns[b].ans << "\n";
		} // for(b)
		
		PrintStar();
		fout << "\n";
			
	} // for(a)
	fout.close();
} // main()

void Calculate(vector<int> allOfNum, vector<Info> &allOfAns, int sum, int level, string formula) {
	if ( level < allOfNum.size() ) {
		Calculate(allOfNum, allOfAns, sum + allOfNum[level], level + 1, formula + " + " + IntToString(allOfNum[level]));
		Calculate(allOfNum, allOfAns, sum - allOfNum[level], level + 1, formula + " - " + IntToString(allOfNum[level]));
	} // if()
	else {
		Info i;
		i.ans = sum;
		i.formula = formula;
		i.divisible = false;
		allOfAns.push_back(i);
	} // else
} // Calculate()

string IntToString(int num) {
	if ( num == 0 )
	  return "0";
	else {
		bool negative = false;
		
		if ( num < 0 ) {
			negative = true;
			num = -num;
		} // if()
		
		string re = "";
		while ( num > 0 ) {
			re = (char)('0' + num % 10) + re;
			num /= 10;
		} // while()

		if ( negative )
			re = "(-" + re + ")";

		return re;
	} // else
} // IntToString()

bool CheckDivisible(vector<Info> &allOfAns, int K) {
	bool re = false;
	for ( int a = 0 ; a < allOfAns.size() ; a++ )
		if ( allOfAns[a].ans % K == 0 ) allOfAns[a].divisible = re = true;

	return re;
} // CheckDivisible()

void PrintStar() {
	fout << "******************************\n";
} // PrintStar()
