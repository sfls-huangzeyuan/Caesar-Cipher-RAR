#include<iostream>
#include<string>
using namespace std;
enum MODE
{
	ENCODE = 1,
	DECODE = -1
};
string ceaser (string plain_text, int mode, int STEP)
{
	if (STEP >= 26) STEP %= 26;
	string cipher = "";
	for (int i = 0; i < plain_text.size(); i++) {
		if (plain_text[i] >= 48 && plain_text[i] <= 57) {
			cipher.push_back (plain_text[i]);
		} else if (plain_text[i] >= 65 && plain_text[i] <= 90) {
			cipher.push_back ( (char) (65 + (plain_text[i] + mode * STEP - 65) % 26));
		} else {
			cipher.push_back ( (char) (97 + (plain_text[i] + mode * STEP - 97) % 26));
		}
	}
	return cipher;
}
string ceaser_encoding (string plain, int STEP)
{
	return ceaser (plain, ENCODE, STEP);
}
string ceaser_decoding (string plain, int STEP)
{
	return ceaser (plain, DECODE, STEP);
}
int main()
{
	string cipher;
	int n=1;
	//getline (cin, cipher);
	cipher="helloworld";
	string res = ceaser_encoding (cipher, n);
	cout << "密文：" << res << endl;
	cout << "明文：" << ceaser_decoding (res, n) << endl;
	return 0;
}
