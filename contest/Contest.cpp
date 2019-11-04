#include "Contest.h"

using namespace std;

struct Board
{
	int iRows = 0;
	int iCols = 0;

	std::vector<PI> vPositions;

	PI getPos(int i)
	{
		PI pos;

		pos.first = ((i - 1) / iCols) + 1;
		pos.second = ((i-1) % iCols) + 1;

		return pos;
	}
};

inline ofstream &operator <<(ofstream & output, const Board& rStruct)
{

	for (auto& pos : rStruct.vPositions)
		output << pos << " ";

	return output;
}

inline ifstream &operator >>(ifstream & input, Board& rA)
{
	input >> rA.iRows;
	input >> rA.iCols;

	int iNumPos = 0;
	input >> iNumPos;

	for (int i = 0; i < iNumPos; ++i)
	{
		int iPos;
		input >> iPos;

		PI pos = rA.getPos(iPos);

		rA.vPositions.push_back(pos);
	}

	return input;
}

/***********************************************************************************
************************************************************************************/
void Contest::Run(ifstream & input, ofstream & output)
{
	Board board;
	input >> board;

	output << board;
}