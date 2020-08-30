#pragma once
/// <summary>
/// This class is responsible for data input validation.
/// </summary>
class validator
{
	public: void inputValidSupply(int pos, int* coin_box);

	public: void inputValidBleed(int pos, int* coin_box);

	public: int inputValidChange(int value);
};

