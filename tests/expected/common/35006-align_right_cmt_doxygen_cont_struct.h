/*
 * Shared by the C and the C++ tests: documenting the attributes of a struct
 * in a header, with Doxygen 'after member' comments whose continuation lines
 * have been brought back to the beginning of the line.
 *
 * No two declarations have the same length, so nothing is already aligned in
 * the input.
 */

#ifndef ALIGN_RIGHT_CMT_DOXYGEN_CONT_STRUCT_H_INCLUDED
#define ALIGN_RIGHT_CMT_DOXYGEN_CONT_STRUCT_H_INCLUDED

/** A point of the mesh. */
struct point
{
	double x;                       /*!< abscissa of the point */
	float y_ord;                    /*!< ordinate of the point */
	double z_elevation_above_datum; /*!< elevation of the point... */
	/*!< ...always zero for a 2D mesh */
	unsigned tag;                   /*!< user tag attached to the point */
};

/** An element of the mesh. */
typedef struct
{
	int id;                      /**< identifier of the element... */
	/**< ...unique within a given mesh */
	unsigned short nb_nodes;     /**< number of nodes of the element */
	int *nodes;                  /**< indices of the nodes, in the order... */
	/**< ...expected by the reference element... */
	/**< ...and never reordered afterwards */
	long double quality_measure; /**< quality of the element */
} element_t;

/** The mesh itself. */
struct mesh
{
	struct point *nodes;             /*!< coordinates of the nodes */
	element_t *elems;                /*!< elements of the mesh... */
	/*!< ...sorted by increasing identifier */
	unsigned nb_nodes;               /*!< number of entries of nodes */
	unsigned long nb_elements_total; /*!< number of entries of elems */
};

#endif /* ALIGN_RIGHT_CMT_DOXYGEN_CONT_STRUCT_H_INCLUDED */
