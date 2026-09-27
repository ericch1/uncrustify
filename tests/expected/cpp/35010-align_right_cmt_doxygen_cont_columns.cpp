/* Test file for align_right_cmt_doxygen_cont: the column the continuation
 * lines sit in must not change the result. */

/* ============================================================
 * Section 1: one continuation, in every original column
 * ============================================================ */

struct Columns
{
	int a;                         //!< a: already aligned
	                               //!< ...continued
	int bb;                        //!< bb: at the code indent
	                               //!< ...continued
	int ccc;                       //!< ccc: in column 1
	                               //!< ...continued
	int dddd;                      //!< dddd: two columns to the left
	                               //!< ...continued
	int eeeee;                     //!< eeeee: far to the right
	                               //!< ...continued
};

/* ============================================================
 * Section 2: continuations spread over several columns
 * ============================================================ */

struct Chains
{
	int a;                         //!< a...
	                               //!< ...in column 1
	                               //!< ...at the code indent
	                               //!< ...far to the right
	long bb;                       ///< bb...
	                               ///< ...somewhere
	                               ///< ...at the code indent
};

/* ============================================================
 * Section 3: heads which are not 'after member' comments
 * ============================================================ */

struct Heads
{
	int a;                         // a plain trailing comment...
	                               //!< ...continued by an 'after member' one
	int bb;                        /*!< a C comment spread
	                                    over two lines... */
	                               /*!< ...continued in column 1 */
	int ccc;                       //!< ccc
};

/* ============================================================
 * Section 4: a head after a closing brace, and nested levels
 * ============================================================ */

struct Outer
{
	struct Inner
	{
		int a;                 //!< a...
		                       //!< ...continued
	} inner;                       //!< inner...
	                               //!< ...continued
	int bb;                        //!< bb
};
