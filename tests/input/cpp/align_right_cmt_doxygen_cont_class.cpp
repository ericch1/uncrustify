/*
 * Documenting the attributes of a C++ class with Doxygen 'after member'
 * comments whose continuation lines have been brought back to the beginning
 * of the line.
 */

#include <string>
#include <vector>

/** A mesh, built once and then queried. */
class Mesh
{
public:
    Mesh() = default;

    bool build();

private:
    int m_id = 0; //!< unique identifier of the mesh
    double m_tolerance = 1e-12; //!< geometric tolerance used when...
    //!< ...merging two coincident vertices
    std::vector<double> m_nodes; //!< coordinates of the nodes, stored as...
    //!< ...x0, y0, z0, x1, y1, z1...
    //!< ...and so on for every node
    bool m_is_built = false; //!< whether build() has already been called

protected:
    static unsigned s_instance_count; ///< number of living instances...
    ///< ...shared by every mesh

public:
    std::string m_name; ///< human readable name of the mesh
};

/** The very same attributes, documented with C comments. */
class MeshC
{
private:
    int m_id = 0; /**< unique identifier of the mesh */
    double m_tolerance = 1e-12; /**< geometric tolerance used when... */
    /**< ...merging two coincident vertices */
    bool m_is_built = false; /*!< whether build() has already been called... */
    /*!< ...reset by every call to clear() */
    unsigned long m_nb_nodes = 0; /*!< number of nodes of the mesh */
};

/** Attributes of a struct, which are public by default. */
struct Bounds
{
    double m_x = 0.0; //!< lower bound along x
    double m_x_upper_limit = 0.0; //!< upper bound along x...
    //!< ...never smaller than m_x
    float m_y_low = 0.0f; //!< lower bound along y
    long double m_y_upper_limit_of_the_domain = 0.0; //!< upper bound along y

    /** A nested class has its own alignment group. */
    class Padding
    {
private:
        double m_left = 0.0; //!< padding added on the left...
        //!< ...expressed in the unit of the mesh
        unsigned m_right_hand_side_padding = 0; //!< padding added on the right
    };
};
