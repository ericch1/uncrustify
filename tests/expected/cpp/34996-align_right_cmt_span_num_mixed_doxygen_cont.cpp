/* Test file for align_right_cmt_doxygen_cont combined with the
 * align_right_cmt_span budget options.
 *
 * Copied from align_right_cmt_span_num_mixed.cpp and reworked so that every
 * kind of traversed line (empty, preprocessor, comment) is crossed by groups
 * that contain Doxygen 'after member' continuation lines.  Every continuation
 * is written at the beginning of the line, which is what the option is about.
 *
 * The point of interest: without the option a continuation line is an
 * ordinary comment line and eats the align_right_cmt_span_num_cmt_lines
 * budget, so a long block of documentation breaks the group; with the option
 * it is a right comment, so it resets the span and refills the budget
 * instead.
 *
 * Identifier lengths are deliberately all different, so that nothing is
 * already aligned in the input.
 */

/* ============================================================
 * Section 1: continuations versus the comment budget
 * ============================================================ */

void test_cont_vs_cmt_budget(void)
{
	int a = 1;                  //!< comment a
	int bb_longer = 2;          //!< comment bb_longer...
	                            //!< ...continued once
	int ccc_even_longer = 3;    //!< comment ccc_even_longer...
	                            //!< ...continued once
	                            //!< ...continued twice
	int dddd_still_longer = 4;  //!< comment dddd_still_longer...
	                            //!< ...continued once
	                            //!< ...continued twice
	                            //!< ...continued three times
	int eeeee_the_last_one = 5; //!< comment eeeee_the_last_one
}

void test_standalone_still_costs_budget(void)
{
	int a = 1;               //!< comment a
	int bb_longer = 2;       //!< comment bb_longer
	// a standalone comment, not an 'after member' one
	int ccc_even_longer = 3; //!< comment ccc_even_longer
	// standalone C++ comment A
	// standalone C++ comment B
	int dddd_still_longer = 4; //!< comment dddd_still_longer
	// standalone C++ comment X
	// standalone C++ comment Y
	// standalone C++ comment Z
	int eeeee_the_last_one = 5; //!< comment eeeee_the_last_one
}

/* ============================================================
 * Section 2: continuations versus the empty line budget
 * ============================================================ */

void test_cont_vs_empty_budget(void)
{
	int a = 1;         //!< comment a...
	                   //!< ...continued once

	int bb_longer = 2; //!< comment bb_longer...
	                   //!< ...continued once
	                   //!< ...continued twice


	int ccc_even_longer = 3; //!< comment ccc_even_longer...
	                         //!< ...continued once



	int dddd_the_longest_one = 4; //!< comment dddd_the_longest_one
}

void test_empty_line_breaks_the_chain(void)
{
	int a = 1;               //!< comment a

	//!< a blank line separates it, so this is not a continuation
	int bb_longer = 2;       //!< comment bb_longer...
	                         //!< ...this one is a continuation
	int ccc_even_longer = 3; //!< comment ccc_even_longer
}

/* ============================================================
 * Section 3: continuations versus the preprocessor budget
 * ============================================================ */

void test_cont_vs_pp_budget(void)
{
	int a = 1;         //!< comment a...
	                   //!< ...continued once
#define CONT_PP_1 1
	int bb_longer = 2; //!< comment bb_longer...
	                   //!< ...continued once
	                   //!< ...continued twice
#define CONT_PP_2 2
#define CONT_PP_22 22
	int ccc_even_longer = 3; //!< comment ccc_even_longer...
	                         //!< ...continued once
#define CONT_PP_3 3
#define CONT_PP_33 33
#define CONT_PP_333 333
	int dddd_the_longest_one = 4; //!< comment dddd_the_longest_one
}

void test_pp_line_breaks_the_chain(void)
{
	int a = 1;               //!< comment a
#define CONT_PP_4 4
	//!< a #define separates it, so this is not a continuation
	int bb_longer = 2;       //!< comment bb_longer...
	                         //!< ...this one is a continuation
	int ccc_even_longer = 3; //!< comment ccc_even_longer
}

/* ============================================================
 * Section 4: everything mixed
 * ============================================================ */

void test_cont_mixed_lines(void)
{
	int a = 1;                       //!< comment a...
	                                 //!< ...continued once

	/* standalone C comment 1 */
	int bb_longer = 2;               //!< comment bb_longer...
	                                 //!< ...continued once
	                                 //!< ...continued twice

#define CONT_MIX_1 1
	int ccc_even_longer = 3;         //!< comment ccc_even_longer...
	                                 //!< ...continued once

#define CONT_MIX_2 2
	// standalone C++ comment A
	int dddd_a_bit_longer = 4;       //!< comment dddd_a_bit_longer...
	                                 //!< ...continued once
	                                 //!< ...continued twice
	                                 //!< ...continued three times
	/* standalone C comment X */
#define CONT_MIX_3 3

	int eeeee_even_longer_still = 5; //!< comment eeeee_even_longer_still...
	                                 //!< ...continued once


	int ffffff_the_very_last = 6; //!< comment ffffff_the_very_last
}

/* ============================================================
 * Section 5: what must not be taken for a continuation
 * ============================================================ */

void test_cont_kind_mismatch(void)
{
	int a = 1;                    //!< a C++ trailing comment
	/*!< a C comment is not the continuation of a C++ one */
	int bb_longer = 2;            /*!< a C trailing comment */
	//!< a C++ comment is not the continuation of a C one
	int ccc_even_longer = 3;      //!< comment ccc_even_longer...
	                              //!< ...this one is a continuation
	int dddd_the_longest_one = 4; //!< comment dddd_the_longest_one
}

void test_cont_marker_mismatch(void)
{
	int a = 1;                    //!< comment a
	//! not an 'after member' marker
	int bb_longer = 2;            //!< comment bb_longer
	/// not an 'after member' marker either
	int ccc_even_longer = 3;      //!< comment ccc_even_longer
	// not an 'after member' marker either
	int dddd_the_longest_one = 4; //!< comment dddd_the_longest_one
}

/* Mixing the two C++ 'after member' markers is allowed: what is compared is
 * the kind of the comment, not the marker itself. */
void test_cont_marker_mixing(void)
{
	int a = 1;               //!< comment a...
	                         ///< ...continued with the other marker
	int bb_longer = 2;       ///< comment bb_longer...
	                         //!< ...continued with the other marker
	int ccc_even_longer = 3; //!< comment ccc_even_longer
}

/* A block comment spread over several lines and a block comment written on a
 * single line are the same kind, so they continue each other in both
 * directions.  Doxygen attaches all of them to the preceding member. */
void test_cont_after_multiline_block(void)
{
	int a = 1;               /*!< comment a
	                              written on two lines */
	                         /*!< the continuation of a multi-line block comment */
	int bb_longer = 2;       /*!< comment bb_longer */
	                         /*!< a continuation
	                              itself written on two lines */
	int ccc_even_longer = 3; /*!< comment ccc_even_longer */
}

/* ============================================================
 * Section 6: class attributes crossing every kind of line
 * ============================================================ */

class DocumentedAttributes
{
private:
int m_n {1};                                      //!< the counter
double m_relative_tolerance {1e-12};              //!< tolerance used when...
                                                  //!< ...comparing two coordinates

#define ATTR_PP_1 1
bool m_ok {false};                                //!< whether the last call succeeded

/* a standalone C comment between two attributes */
unsigned long m_number_of_processed_elements {0}; //!< how many elements...
                                                  //!< ...have been processed so far...
                                                  //!< ...reset by every call to clear()
char m_c {'x'};                                   //!< a single character


short m_small_one {0}; //!< a short one...
                       //!< ...documented on two lines
};
