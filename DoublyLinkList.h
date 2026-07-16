#pragma once
#include"Chunk.h"

class Node {
	Chunk data;
public:
	Node* next; 
	Node* prev;

	Node() : data(Chunk()), next(nullptr), prev(nullptr) {}
	Node(Chunk chunk) : data(chunk), next(nullptr), prev(nullptr) {}
	Chunk GetData() { return data; }

};