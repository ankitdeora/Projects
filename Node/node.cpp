#include "node.h"

node::node()
{
	m_next = NULL;
	m_key = 0;
}

node::node(int key)
{
	m_next = NULL;
	m_key = key;
}

node::node(int key, node *next)
{
	m_next = next;
	m_key = key;
}

node::~node()
{
}

