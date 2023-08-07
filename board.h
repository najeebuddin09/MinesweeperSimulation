#pragma once

#include <vector>
#include <iostream>

template <typename T>
class board {
protected:
	std::vector<std::vector<T>> board;
	void _reset(int rows, int cols);
	void _draw(int rows, int cols, std::ostream&) const;
public:
	virtual void draw(std::ostream&) const = 0;
	virtual void set(int,int,T) = 0;
	virtual T get(int,int) = 0;
	virtual int getNoRows() = 0;
	virtual int getNoCols() = 0;
	virtual int getNoMines() = 0;
};

template <typename T>
class bBoard : public board<T> {
public:
	enum boardDimentions {
		bdROWS = 9,
		bdCOLS = 9
	};
	enum {
		MINES = 10
	};
public:
	bBoard();
	void set(int,int,T);
	T get(int,int);
	virtual void draw(std::ostream&) const;
	int getNoRows();
	int getNoCols();
	int getNoMines();
};

template <typename T>
class iBoard : public board<T> {
public:
	enum boardDimentions {
		bdROWS = 16,
		bdCOLS = 16
	};
	enum {
		MINES = 40
	};
public:
	iBoard();
	void set(int,int,T);
	T get(int,int);
	virtual void draw(std::ostream&) const;
	int getNoRows();
	int getNoCols();
	int getNoMines();
};

template <typename T>
class eBoard : public board<T> {
public:
	enum boardDimentions {
		bdROWS = 16,
		bdCOLS = 30
	};
	enum {
		MINES = 99
	};
public:
	eBoard();
	void set(int,int,T);
	T get(int,int);
	virtual void draw(std::ostream&) const;
	int getNoRows();
	int getNoCols();
	int getNoMines();
};

template <typename T>
class gBoard : public board<T> {
public:
	enum boardDimentions {
		bdROWS = 16,
		bdCOLS = 16
	};
	enum {
		MINES = 20,
		GRENADES = 20
	};
public:
	gBoard();
	virtual void draw(std::ostream&) const;
	void set(int,int,T);
	T get(int,int);
	int getNoRows();
	int getNoCols();
	int getNoMines();
};

