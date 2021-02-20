#ifndef POSITION_H
#define POSITION_H

class position
{
private:
    /*!
     * \brief Attribute representing the x of the square.
     */
    int m_x;
    /*!
     * \brief Attribute representing the y of the square.
     */
    int m_y;
    /*!
     * \brief Attribute representing the z of the square.
     */
    int m_z;

public:
    /*!
     * \brief  
     */
    position();
    /*!
     * \brief Getter of the value of the m_x attribute.
     * \return Interger for one of the cardinal position (x).
     */
    int getX();
    /*!
     * \brief Getter of the value of the m_y attribute.
     * \return Interger for one of the cardinal position (y).
     */
    int getY();
    /*!
     * \brief Getter of the value of the m_z attribute.
     * \return Interger for one of the cardinal position (z).
     */
    int getZ();
    /*!
     * \brief Setter of the attribute X
     * \param x The new x cardinal.
     */
    void setX(int x);
    /*!
     * \brief Setter of the attribute Y
     * \param x The new y cardinal.
     */
    void setY(int y);
    /*!
     * \brief Setter of the attribute Z
     * \param x The new z cardinal.
     */
    void setZ(int z);
};

#endif // POSITION_H
