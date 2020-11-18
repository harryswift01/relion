#include <src/args.h>
#include <mpi.h>
#include <src/jaz/tomography/programs/align_mpi.h>


int main(int argc, char *argv[])
{
	try
	{
		AlignProgramMpi ap(argc, argv);
		ap.run();
	}
	catch (RelionError XE)
	{
		MPI_Abort(MPI_COMM_WORLD, RELION_EXIT_FAILURE);
		return RELION_EXIT_FAILURE;
	}

	MPI_Barrier(MPI_COMM_WORLD);

	return RELION_EXIT_SUCCESS;
}
