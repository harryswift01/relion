#ifndef TOMO_MAG_FIT_H
#define TOMO_MAG_FIT_H

#include <src/jaz/tomography/tomogram.h>
#include <src/jaz/tomography/particle_set.h>
#include <src/jaz/tomography/reference_map.h>


class TomoMagFit
{
	public:

		TomoMagFit(
				const std::vector<int>& particle_indices,
				const Tomogram& tomogram,
				const ParticleSet& particleSet,
				const TomoReferenceMap& referenceMap,
				int boxSize,
				int first_frame,
				int last_frame,
				int num_threads);


			int boxSize, first_frame, last_frame, num_threads;
			const std::vector<int>& particle_indices;
			const Tomogram& tomogram;
			const ParticleSet& particleSet;
			const TomoReferenceMap& referenceMap;

};

class TomoIsoMagFit : public TomoMagFit
{
	public:

		TomoIsoMagFit(
				const std::vector<int>& particle_indices,
				const Tomogram& tomogram,
				const ParticleSet& particleSet,
				const TomoReferenceMap& referenceMap,
				int boxSize,
				int first_frame,
				int last_frame,
				int num_threads);

		gravis::d2Vector computeErrorAndSlope(double mag);
};

#endif
