#include <cstdlib>
namespace Project {
	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	ref class Player
	{
	private: int n;

	public:
		Player(int n) { this->n = n; }

		int Move(int value)
		{
			if (value == 0) return n;
			return -n;
		}

		int GetVal()
		{
			return n;
		}
	};

	ref class PaperTable
	{
	private:
		int** arr;
		int row;
		int col;
		PictureBox^ myPB;

		int** GetArr()
		{
			int** arr = new int* [row];
			for (int i = 0; i < row; i++)
				arr[i] = new int[col];

			for (int i = 0; i < row; i++)
				for (int j = 0; j < col; j++)
					arr[i][j] = 0;
			return arr;
		}
	public:
		PaperTable(int size,const int Xvalue, const int Ovalue, PictureBox^ pb)
		{
			if (size == 0) std::abort(); //include cstdlib
			row = col = size;
			arr = GetArr();

			Add(size - 1, 0, Xvalue);
			Add(size - 2, 0, Xvalue);
			Add(size - 1, 1, Xvalue);

			Add(0, size - 1, Ovalue);
			Add(0, size - 2, Ovalue);
			Add(1, size - 1, Ovalue);

			myPB = pb; 
		}

		void Add(int i, int j, int n)
		{
			arr[i][j] = n;
		}

		int GetVal(int i, int j)
		{
			return arr[i][j];
		}

		bool isMoveLegal(int i, int j, int n)
		{
			bool legal = false;
			if (arr[i][j] == n || arr[i][j] < 0) return legal;

			--i;
			--j;
			for (int k = 0; k < 3; k++)
			{
				for (int g = 0; g < 3; g++)
				{
					if (i + k < row && j + g < col && i + k > -1 && j + g > -1)
					{
						if (arr[i + k][j + g] == -n)
						{
							arr[i + k][j + g] = 0;
							if(!legal) legal = isMoveLegal(i + k, j + g, n);
							arr[i + k][j + g] = -n;
						}
						if (arr[i + k][j + g] == n) legal = true;
					}
				}
			}

			return legal;
		}

		bool isDefeated(int enemvalue)
		{
			for (int i = 0; i < row; i++)
				for (int j = 0; j < col; j++)
					if (arr[i][j] == enemvalue) return false;
			return true;
		}

		bool isFull()
		{
			for (int i = 0; i < row; i++)
				for (int j = 0; j < col; j++)
					if (arr[i][j] == 0) return false;
			return true;
		}

		void DrawLight(int Xvalue, int Ovalue)
		{
			Bitmap^ bmp;
			bmp = gcnew Bitmap("myTable.jpg");
			Graphics^ g = Graphics::FromImage(bmp);
			Image^ imageX = Image::FromFile("playerX.png");
			Image^ imageNoX = Image::FromFile("playerNoX+.png");
			Image^ imageO = Image::FromFile("playerO.png");
			Image^ imageNoO = Image::FromFile("playerNoO.png");

			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					if (arr[i][j] == Xvalue)  g->DrawImage(imageX, 5 + j * 80, 5 + i * 80, imageX->Size.Width, imageX->Size.Height);
					if (arr[i][j] == -Xvalue) g->DrawImage(imageNoO, 5 + j * 80, 5 + i * 80, imageNoO->Size.Width, imageNoO->Size.Height);
					if (arr[i][j] == Ovalue)  g->DrawImage(imageO, 5 + j * 80, 5 + i * 80, imageO->Size.Width, imageO->Size.Height);
					if (arr[i][j] == -Ovalue) g->DrawImage(imageNoX, 5 + j * 80, 5 + i * 80, imageNoX->Size.Width, imageNoX->Size.Height);
				}
			}
			myPB->Size = bmp->Size;
			myPB->Image = bmp;
		}

		void DrawDark(int Xvalue, int Ovalue)
		{
			Bitmap^ bmp;
			bmp = gcnew Bitmap("myTable_space+.jpg");
			Graphics^ g = Graphics::FromImage(bmp);
			Image^ imageX = Image::FromFile("playerX_dark.png");
			Image^ imageNoX = Image::FromFile("playerNoX+_dark.png");
			Image^ imageO = Image::FromFile("playerO_dark.png");
			Image^ imageNoO = Image::FromFile("playerNoO_dark.png");

			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					if (arr[i][j] == Xvalue)  g->DrawImage(imageX, 5 + j * 80, 5 + i * 80, imageX->Size.Width, imageX->Size.Height);
					if (arr[i][j] == -Xvalue) g->DrawImage(imageNoO, 5 + j * 80, 5 + i * 80, imageNoO->Size.Width, imageNoO->Size.Height);
					if (arr[i][j] == Ovalue)  g->DrawImage(imageO, 5 + j * 80, 5 + i * 80, imageO->Size.Width, imageO->Size.Height);
					if (arr[i][j] == -Ovalue) g->DrawImage(imageNoX, 5 + j * 80, 5 + i * 80, imageNoX->Size.Width, imageNoX->Size.Height);
				}
			}
			myPB->Size = bmp->Size;
			myPB->Image = bmp;
		}

		void DrawTheEnd(System::String ^s) //clear
		{
			Bitmap^ bmp;
			bmp = gcnew Bitmap(myPB->Width, myPB->Height);
			Graphics^ g = Graphics::FromImage(bmp);
			g->DrawString(s + " is Winner", gcnew Drawing::Font("Times New Roman", 50), Brushes::Black, PointF(150, 50));
			myPB->Image = bmp;
		}

		void DrawTheEnd() //clear
		{
			Bitmap^ bmp;
			bmp = gcnew Bitmap(myPB->Width, myPB->Height);
			Graphics^ g = Graphics::FromImage(bmp);
			g->DrawString("Draw", gcnew Drawing::Font("Times New Roman", 50), Brushes::Black, PointF(300, 50));
			myPB->Image = bmp;
		}

		~PaperTable()
		{
			for (int i = 0; i < row; i++)
				delete[] arr[i];

			delete[] arr;

		}
	};
}
