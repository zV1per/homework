#pragma once
class linkedlist
{
private:
	struct PIONT
	{
		int data;
		PIONT* next;
	};
	PIONT* head;
	int length;
	
public:
	linkedlist() :head(nullptr),length(0){};
	~linkedlist() { Clearlist(); };
	bool Isempty(void);
	bool Clearlist(void);
	int Getdata(int num);
	int Searchdata(int num);
	bool Addpiont(int data,int num);
	bool Deletepiont(int num);
	void Traverselist(void);
	int Getlength(void) const;
	int Getmidpiont(void);
	bool Iscircle(void);
	bool Invert(void);
	bool Upsidedown(void);//·ÇµÝ¹é
	void Upsidedown_Recursion(PIONT* ptr);//µÝ¹é
	void run(void);
};

