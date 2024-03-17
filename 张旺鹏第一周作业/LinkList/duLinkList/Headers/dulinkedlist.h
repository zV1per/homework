#pragma once
class dulinkedlist
{
public:
	dulinkedlist() :head(nullptr), length(0) {};
	~dulinkedlist() { Clearlist(); };
	bool Isempty(void);
	bool Clearlist(void);
	int Getdata(int num);
	int Searchdata(int num);
	bool Addpiont(int data, int num);
	bool Deletepiont(int num);
	void Traverselist(void);
	int Getlength(void) const;
	void run(void);
private:
	struct PIONT
	{
		int data;
		PIONT* next;
		PIONT* prev;
	};
	PIONT* head;
	int length;
};

