//#include <iostream>
//#include "program.h"
//#include "tests.h"
//using namespace std;
//
//int main()
//{
//	tests();
//	run();
//}

//#include <iostream>
//
//using namespace std;
//
//int isPrimee(int n)
//{
//	if (n == 2) return true;
//	if (n % 2 == 0 || n < 2) return false;
//	for (int i = 2; i <= n / 2; i++)
//		if (n % i == 0)
//			return false;
//	return true;
//}
//
//int main()
//{
//	int n, p1 = 0, p2 = 0;
//	int v[4] = { 2, 3, 5, 7 };
//	bool ok = false;
//	cin >> n;
//
//	for (int i = 0; i < 4; i++)
//	{
//		p1 = v[i];
//		p2 = n - p1;
//		if (isPrimee(p2))
//		{
//			ok = true;
//			break;
//		}
//		else continue;
//	}
//
//	if (ok)
//		cout << p1 << " " << p2;
//	else
//		cout << "nu se poate";
//}

#include <iostream>

using namespace std;

int main()
{
	int a, b, ans = 0;
	cin >> a >> b;
	while (a > 0)
	{
		if (a % 2 == 1)
			ans += b;
		a /= 2;
		b *= 2;
	}
	cout << ans;
}