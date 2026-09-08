class DocumentedClass
{
private:
    int a {1}; //!< comment a
    int bb; //!< comment bb


    int ccc {3}; //!<  comment ccc
              //!<this is a long explanation
              //!<   of the attribute in doxygen
              //!<format that many people use BUT WHY ARE THESE 3 LINES ALIGNED in the result?...
};
