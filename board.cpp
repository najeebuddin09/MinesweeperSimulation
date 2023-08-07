#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <ios>
#include <iostream>
#include "board.h"

template <typename T>
void board<T>::_draw(int rows, int cols, std::ostream& out) const {
	for_each(board.begin(), board.end(), [&out](auto row) {
		for_each(row.begin(), row.end(), [&out](auto box) {
			out << std::setw(3) << box;
		});
		out << std::endl;
	});
}

template <typename T>
void board<T>::_reset(int rows, int cols) {
	for (int i = 0; i < rows; i++){
		std::vector<T> t(cols, 'B');
		board::board.push_back(t);
	}
}

template <typename T>
bBoard<T>::bBoard() {
	board<T>::_reset(bdROWS, bdCOLS);
}

template <typename T>
void bBoard<T>::draw(std::ostream& out) const {
	board<T>::_draw(bdROWS, bdCOLS, out);
}

template <typename T>
iBoard<T>::iBoard() {
	board<T>::_reset(bdROWS, bdCOLS);
}

template <typename T>
void iBoard<T>::draw(std::ostream& out) const {
	board<T>::_draw(bdROWS, bdCOLS, out);
}

template <typename T>
eBoard<T>::eBoard() {
	board<T>::_reset(bdROWS, bdCOLS);
}

template <typename T>
void eBoard<T>::draw(std::ostream& out) const {
	board<T>::_draw(bdROWS, bdCOLS, out);
}

template <typename T>
gBoard<T>::gBoard() {
	board<T>::_reset(bdROWS, bdCOLS);
}

template <typename T>
void gBoard<T>::draw(std::ostream& out) const {
	board<T>::_draw(bdROWS, bdCOLS, out);
}

template <typename T>
void bBoard<T>::set(int i, int j, T val) {
	if (i < 0 || i >= bdROWS || j < 0 || j >= bdCOLS) return;
	board<T>::board[i][j] = val;
}

template <typename T>
void iBoard<T>::set(int i, int j, T val) {
	if (i < 0 || i >= bdROWS || j < 0 || j >= bdCOLS) return;
	board<T>::board[i][j] = val;
}

template <typename T>
void eBoard<T>::set(int i, int j, T val) {
	if (i < 0 || i >= bdROWS || j < 0 || j >= bdCOLS) return;
	board<T>::board[i][j] = val;
}

template <typename T>
void gBoard<T>::set(int i, int j, T val) {
	if (i < 0 || i >= bdROWS || j < 0 || j >= bdCOLS) return;
	board<T>::board[i][j] = val;
}

template <typename T>
T bBoard<T>::get(int i, int j) {
	if (i < 0 || i >= bdROWS || j < 0 || j >= bdCOLS) return 99;
	return board<T>::board[i][j];
}

template <typename T>
T iBoard<T>::get(int i, int j) {
	if (i < 0 || i >= bdROWS || j < 0 || j >= bdCOLS) return 99;
	return board<T>::board[i][j];
}

template <typename T>
T eBoard<T>::get(int i, int j) {
	if (i < 0 || i >= bdROWS || j < 0 || j >= bdCOLS) return 99;
	return board<T>::board[i][j];
}

template <typename T>
T gBoard<T>::get(int i, int j) {
	if (i < 0 || i >= bdROWS || j < 0 || j >= bdCOLS) return 99;
	return board<T>::board[i][j];
}

template <typename T>
int bBoard<T>::getNoRows() {
	return bdROWS;
}

template <typename T>
int iBoard<T>::getNoRows() {
	return bdROWS;
}

template <typename T>
int eBoard<T>::getNoRows() {
	return bdROWS;
}

template <typename T>
int gBoard<T>::getNoRows() {
	return bdROWS;
}

template <typename T>
int bBoard<T>::getNoCols() {
	return bdCOLS;
}

template <typename T>
int iBoard<T>::getNoCols() {
	return bdCOLS;
}

template <typename T>
int eBoard<T>::getNoCols() {
	return bdCOLS;
}

template <typename T>
int gBoard<T>::getNoCols() {
	return bdCOLS;
}

template <typename T>
int bBoard<T>::getNoMines() {
	return MINES;
}

template <typename T>
int iBoard<T>::getNoMines() {
	return MINES;
}

template <typename T>
int eBoard<T>::getNoMines() {
	return MINES;
}

template <typename T>
int gBoard<T>::getNoMines() {
	return MINES;
}

// this is to force compiler to compile for int and char types of class
// explained in book page 850
template class bBoard<int>;
template class bBoard<char>;
template class iBoard<int>;
template class iBoard<char>;
template class eBoard<int>;
template class eBoard<char>;
template class gBoard<int>;
template class gBoard<char>;

