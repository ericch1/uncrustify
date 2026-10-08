/* Test file for align_right_cmt_doxygen_cont. */

/* ============================================================
 * Section 1: local variables
 * ============================================================ */

void test_c_cmt_doxygen_cont_locals(void)
{
    int a = 1; /*!< comment a */
    int bb = 2; /*!< comment bb... */
    /*!< ...continued */
    int ccc = 3; /*!< comment ccc... */
/*!< ...continued in column 1 */
                          /*!< ...continued further right */
    int dddd = 4; /*!< comment dddd... */
      /*!< ...continued */
         /*!< ...continued */
    /*!< ...continued */
    int eeeee_long = 5; /*!< comment eeeee_long */
}

/* ============================================================
 * Section 2: continuations already aligned
 * ============================================================ */

void test_c_cmt_doxygen_cont_aligned(void)
{
    int a = 1;          /**< comment a */
    int bb = 2;         /**< comment bb... */
                        /**< ...continued */
    int eeeee_long = 5; /**< comment eeeee_long */
}

/* ============================================================
 * Section 3: struct members and globals
 * ============================================================ */

struct attributes
{
    int m_a; /*!< the a */
    int m_bbbb; /*!< the bbbb... */
/*!< ...continued */
    int m_cc; /**< the cc... */
                /**< ...continued */
    double m_ddddd; //!< the ddddd...
        //!< ...continued
};

int g_a = 1; /*!< global a */
static double g_tolerance = 1e-12; /*!< global tolerance... */
    /*!< ...continued */
int g_ccc = 3; /*!< global ccc */

enum color
{
    RED, /*!< red... */
/*!< ...continued */
    GREEN_LONGER, /*!< green */
};

/* ============================================================
 * Section 4: what must NOT be taken for a continuation
 * ============================================================ */

void test_c_cmt_doxygen_cont_no_match(void)
{
    int a = 1; /* a plain trailing comment */
    /* a standalone comment describing the next statement */
    int bb = 2; /* a plain trailing comment */

    int ccc = 3; /*!< comment ccc */

    /*!< separated from the comment above by a blank line */
    int dddd = 4; /*!< comment dddd */
    /*! not an 'after member' marker */
    int eeeee = 5; /*!< comment eeeee */
                   //!< C++ comment below a C one
}
