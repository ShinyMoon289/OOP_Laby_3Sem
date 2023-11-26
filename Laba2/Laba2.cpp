#include"Transaction.h"
#include"FlieTypes.h"
#include<memory>
unsigned int graphFile::Count = 0;

using namespace std;
int main()
{
	SmartPointer <pngFile> newfile = new pngFile();
	SmartPointer <Logo<>> myLogo = new Logo<>();
	std::cout<<newfile->showCounter();
	Transaction<pngFile> transaction;
	transaction.beginTransaction("newname", 65);
	transaction.showStates();
	transaction.commit();

	
}
