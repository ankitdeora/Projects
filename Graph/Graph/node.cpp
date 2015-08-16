#include "node.h"

node::node()
{
	m_next = NULL;
	m_key = 0;
	parentKey = -1;
	distance = 0;
}

node::node(int key)
{
	m_next = NULL;
	m_key = key;
	parentKey = -1;
	distance = 0;
}

node::node(int key, node *next)
{
	m_next = next;
	m_key = key;
	parentKey = -1;
	distance = 0;
}

node::~node()
{
}

