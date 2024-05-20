#include <iostream>
#include <string>
using namespace std;

int GetCard(string& CardShape);
void PlayBlackjack();
void PrintResult(int Computer, int Player);
bool CheckIsOne(int Sum , int Card1 , int Card2);

bool CheckIsOne(int Sum, int Card1, int Card2)
{
	return Sum < 12 && (Card1 == 1 || Card2 == 1);
}

void PrintResult(int Computer, int Player)
{
	if (Computer > Player) cout << "��ǻ�� �¸�!!" << endl;
	else if (Computer < Player) cout << "�÷��̾� �¸�!!" << endl;
	else cout << "���º�!!" << endl;
}

void PlayBlackjack()
{
	srand(time(NULL));

	string ComputerCard1Shape;
	string ComputerCard2Shape;
	int ComputerCard1 = GetCard(ComputerCard1Shape);
	int ComputerCard2 = GetCard(ComputerCard2Shape);

	string PlayerCard1Shape;
	string PlayerCard2Shape;
	int PlayerCard1 = GetCard(PlayerCard1Shape);
	int PlayerCard2 = GetCard(PlayerCard2Shape);
	


	cout << "���� ������ �����մϴ�." << endl;
	
	int SumComputerCard = ComputerCard1 + ComputerCard2;
	int SumPlayerCard = PlayerCard1 + PlayerCard2;

	if (CheckIsOne(SumComputerCard , ComputerCard1, ComputerCard2)) SumComputerCard += 10;
	if (CheckIsOne(SumPlayerCard, PlayerCard1, PlayerCard2)) SumPlayerCard += 10;

	cout << "��ǻ�� ī�� : " << ComputerCard1Shape << " , " << ComputerCard2Shape << " �� : " << SumComputerCard << endl;
	cout << "�÷��̾� ī�� : " << PlayerCard1Shape << " , " << PlayerCard2Shape << " �� : " << SumPlayerCard << endl;


	PrintResult(SumComputerCard, SumPlayerCard);
	
}

int GetCard(string& CardShape)
{
	int Card = (rand() % 13) + 1;

	switch (Card)
	{
	case 10:
		CardShape = "10";
		break;
	case 11:
		CardShape = "J";
		break;
	case 12:
		CardShape = "Q";
		break;
	case 13:
		CardShape = "K";
		break;
	default :
		CardShape = Card + 48;
	}
	
	if (Card > 10)
	{
		Card = 10;
	}
	return Card ;

}

int main()
{
	
	PlayBlackjack();
	
	return 0;
}