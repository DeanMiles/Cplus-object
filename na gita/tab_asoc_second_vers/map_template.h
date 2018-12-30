#ifndef _MAP_TEMPLATE_H_
#define _MAP_TEMPLATE_H_
#include <vector>

using namespace std;
template <class key_type, class word_type>

class map_template
{
    struct Node
    {
        key_type key;
        word_type word;
        Node(const key_type& _key, const word_type& _word) : key(_key), word(_word) {};//2ga lista
    };

    vector<Node> values;

    public:
    map_template()
    {
    }
    map_template(const key_type& key, const word_type& word)
    {
        Node BrandNew(key, word) ;
        this->values.pushback(BrandNew) ;
    }

    void Add(const key_type& key, const word_type& word)
    {
        Node BrandNew(key, word) ;
        this->values.push_back(BrandNew) ;
    }

    word_type* Find(const key_type& key)
    {
        unsigned int i;
	for( i = 0 ; i < this->values.size() ; ++i )
        {
            if( key == this->values[i].key )
                return &this->values[i].word ; 
        }
        return NULL;
    }

    friend ostream & operator<<(ostream &display, const map_template <key_type, word_type>& out)
    {
        unsigned int i=0;
        while( i < out.values.size() ) 
	{ 
	    display << "key: " << out.values[i].key << out.values[i].word << endl; ++i ; 
	}
        return display;
    }
};


#endif
