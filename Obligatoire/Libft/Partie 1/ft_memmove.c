void	*ft_memmove(void *dest, const void *src, size_t n);
/*The  memmove() function copies n bytes from memory area src to memory area dest.
 The memory areas may overlap: copying takes place as though the bytes in src are first copied into a temporary array
 that does not overlap src or dest, and the bytes are then copied from the temporary array to dest.*/
// The memmove() function returns a pointer to dest.