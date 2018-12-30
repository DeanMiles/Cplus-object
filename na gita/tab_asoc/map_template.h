#ifndef _MAP_TEMPLATE_H_
#define _MAP_TEMPLATE_H_
#include <vector>
#include <utility>

using namespace std;
template <class ID_type, class word_type>
// #AF
class map_template
{
    vector<pair <ID_type, word_type> > values;

    public:
    void Add(const ID_type& ID,const word_type& word)
    {
	values.push_back(make_pair(ID, word));// first & second
    }

    word_type* Find(const ID_type& ID)
    {
        unsigned int i;
	for( i = 0 ; i < this->values.size() ; ++i )
        {
            if( ID == this->values[i].first )
	    {
                return &this->values[i].second ; //if can find
	    }
        }
        return NULL; // error

    friend ostream & operator<<(ostream &display, const map_template <ID_type, word_type>& out)
    {
        unsigned int i=0;
        while( i < out.values.size() ) 
	{ 
	    display << "key: " << out.values[i].first << out.values[i].second << endl; ++i ; 
	}
        return display;
    }
};


#endif
