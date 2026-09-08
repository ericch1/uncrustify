/* Test file for align_right_cmt_doxygen_cont. */

/* ============================================================
 * Section 1: the continuation lines are brought back to the
 *            beginning of the line
 * ============================================================ */

void test_c_cmt_doxygen_cont_tight(void)
{
	int a = 1;          /*!< comment a */
	int bb = 2;         /*!< comment bb... */
	                    /*!< ...continued */
	int ccc = 3;        /*!< comment ccc... */
	                    /*!< ...continued */
	                    /*!< ...and continued */
	int eeeee_long = 5; /*!< comment eeeee_long */
}

/* ============================================================
 * Section 2: the continuation lines are already aligned
 * ============================================================ */

void test_c_cmt_doxygen_cont_aligned(void)
{
	int a = 1;          /**< comment a */
	int bb = 2;         /**< comment bb... */
	                    /**< ...continued */
	int eeeee_long = 5; /**< comment eeeee_long */
}

/* ============================================================
 * Section 3: struct members
 * ============================================================ */

struct attributes
{
	int m_a;    /*!< the a */
	int m_bbbb; /*!< the bbbb... */
	            /*!< ...continued */
	int m_cc;   /**< the cc... */
	            /**< ...continued */
};

/* ============================================================
 * Section 4: what must NOT be taken for a continuation
 * ============================================================ */

void test_c_cmt_doxygen_cont_no_match(void)
{
	int a = 1;     /* a plain trailing comment */
	/* a standalone comment describing the next statement */
	int bb = 2;    /* a plain trailing comment */

	int ccc = 3;   /*!< comment ccc */

	/*!< separated from the comment above by a blank line */
	int dddd = 4;  /*!< comment dddd */
	/*! not an 'after member' marker */
	int eeeee = 5; /*!< comment eeeee */
}
