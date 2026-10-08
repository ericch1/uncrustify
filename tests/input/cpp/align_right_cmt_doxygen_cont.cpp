/* Test file for align_right_cmt_doxygen_cont. */

/* ============================================================
 * Section 1: local variables
 * ============================================================ */

void test_cpp_cmt_doxygen_cont_locals(void)
{
    int a = 1; //!< comment a
    int bb = 2; //!< comment bb...
    //!< ...continued
    int ccc = 3; //!< comment ccc...
//!< ...continued in column 1
                          //!< ...continued further right
    int dddd = 4; //!< comment dddd...
      //!< ...continued
         //!< ...continued
    //!< ...continued
    int eeeee_long = 5; //!< comment eeeee_long
}

/* ============================================================
 * Section 2: continuations already aligned
 * ============================================================ */

void test_cpp_cmt_doxygen_cont_aligned(void)
{
    int a = 1;               //!< comment a
    int bb = 2;              //!< comment bb...
                             //!< ...continued
    int ccc = 3;             //!< comment ccc...
//!< ...continued in column 1
    int eeeee_long = 5;      //!< comment eeeee_long
}

/* ============================================================
 * Section 3: class members, every 'after member' marker
 * ============================================================ */

class Attributes
{
public:
    int m_a = 1; //!< the a
protected:
    long m_bbbb = 2; //!< the bbbb...
//!< ...continued
    int m_cc = 3; ///< the cc...
                ///< ...continued
private:
    unsigned m_ddddd = 4; /**< the ddddd... */
        /**< ...continued */
    double m_eeeeeeee = 5; /*!< the eeeeeeee... */
                                       /*!< ...continued */
};

/* ============================================================
 * Section 4: globals, namespace and enum
 * ============================================================ */

int g_a = 1; //!< global a
static double g_tolerance = 1e-12; //!< global tolerance...
    //!< ...continued
int g_ccc = 3; //!< global ccc

namespace geo
{
const int kMax = 10; ///< max...
                 ///< ...continued
int kMinimum = 0; ///< min
}

enum Color
{
    RED, //!< red...
//!< ...continued
    GREEN_LONGER, //!< green
};

/* ============================================================
 * Section 5: what must NOT be taken for a continuation
 * ============================================================ */

void test_cpp_cmt_doxygen_cont_no_match(void)
{
    int a = 1; // a plain trailing comment
    // a standalone comment describing the next statement
    int bb = 2; // a plain trailing comment

    int ccc = 3; //!< comment ccc

    //!< separated from the comment above by a blank line
    int dddd = 4; //!< comment dddd
    //! not an 'after member' marker
    int eeeee = 5; //!< comment eeeee
    /* not an 'after member' marker either */
    int ffffff = 6; //!< comment ffffff

    // a standalone comment
    //!< below a standalone comment
    int g = 7; //!< C++ comment
               /*!< C comment below a C++ one */
    int hh = 8; /*!< C comment */
                //!< C++ comment below a C one
    int iii = 9; /*!< C comment */
    /*!< followed by code */ int jjjj = 10;
}

#if 1
#endif /*!< after #endif */
/*!< below a comment after #endif */
