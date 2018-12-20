#ifndef _MAP_TEMPLATE_H_
#define _MAP_TEMPLATE_H_
#include <vector>
#include <utility>

using namespace std;
template <class ID_type, class word_type>

class map_template
{
    //struct Node
    //{
        //ID_type ID;//klucz
        //word_type word;
    //};
    	vector<pair <ID_type, word_type> > values;

    public:
    /*map_template()
    {
    }*/

    /*map_template(const ID_type& ID, const word_type& word) 
    {
        //pair = make_pair(ID, word)) ; // bez obslugi bo wektor obsluzy wyjatek
        this->values.push_back(make_pair(ID, word)) ;
    }*/

    void Add(const ID_type& ID,const word_type& word)
    {
         // bez obslugi bo wektor obsluzy wyjatek
	values.push_back(make_pair(ID, word));
    }

    word_type* Find(const ID_type& ID)
    {
        unsigned int i;
	for( i = 0 ; i < this->values.size() ; ++i )
        {
            if( ID == this->values[i].first )
	    {
                return &this->values[i].second ; //jak znajdzie
	    }
        }
        return NULL; // zwracam nulla jak nie znajdzie i elo
    }

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
