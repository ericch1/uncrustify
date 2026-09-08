/* Test file for align_right_cmt_doxygen_cont. */

/* ============================================================
 * Section 1: the continuation lines are brought back to the
 *            beginning of the line
 * ============================================================ */

void test_cpp_cmt_doxygen_cont_tight(void)
{
	int a = 1;    //!< comment a
	int bb = 2;   //!< comment bb...
	//!< ...continued
	int ccc = 3;  //!< comment ccc...
	//!< ...continued
	//!< ...and continued
	int dddd = 4; //!< comment dddd
	//!< ...continued
	//!< ...and continued
	//!< ...and continued again
	int eeeee_long = 5; //!< comment eeeee_long
}

/* ============================================================
 * Section 2: the continuation lines are already aligned
 * ============================================================ */

void test_cpp_cmt_doxygen_cont_aligned(void)
{
	int a = 1;          //!< comment a
	int bb = 2;         //!< comment bb...
	                    //!< ...continued
	int ccc = 3;        //!< comment ccc...
	                    //!< ...continued
	                    //!< ...and continued
	int eeeee_long = 5; //!< comment eeeee_long
}

/* ============================================================
 * Section 3: every flavour of the 'after member' marker,
 *            on class attributes
 * ============================================================ */

class Attributes
{
private:
int m_a = 1;           //!< the a
long m_bbbb = 2;       //!< the bbbb...
//!< ...continued
int m_cc = 3;          ///< the cc...
///< ...continued
unsigned m_ddddd = 4;  /**< the ddddd... */
/**< ...continued */
double m_eeeeeeee = 5; /*!< the eeeeeeee... */
/*!< ...continued */
};

/* ============================================================
 * Section 4: what must NOT be taken for a continuation
 * ============================================================ */

void test_cpp_cmt_doxygen_cont_no_match(void)
{
	int a = 1;      // a plain trailing comment
	// a standalone comment describing the next statement
	int bb = 2;     // a plain trailing comment

	int ccc = 3;    //!< comment ccc

	//!< separated from the comment above by a blank line
	int dddd = 4;   //!< comment dddd
	//! not an 'after member' marker
	int eeeee = 5;  //!< comment eeeee
	/* not an 'after member' marker either */
	int ffffff = 6; //!< comment ffffff
}
