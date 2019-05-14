// Abstract class

// 	- pure virtual function = 0
// 	- no instances

class Figure {
public:
	void printPublic() {}
protected:
	void printProtected() {}
private:
	void printPrivate() {}
};

class Circle : public Figure {
public:
	void printPublic() {}
protected:
	void printProtected() {}
private:

}

class Square : protected Figure {
protected:
	void printPublic() {}
	void printProtected() {}
private:

}

class Line : private Figure {
private:
	void printPublic() {}
	void printProtected() {}
}



