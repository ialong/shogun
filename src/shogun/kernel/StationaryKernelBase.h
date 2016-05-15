/*
 * Copyright (c) The Shogun Machine Learning Toolbox
 * Written (W) 2016 Alessandro Ialongo
 * Written (W) 2016 Heiko Strathmann
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are those
 * of the authors and should not be interpreted as representing official policies,
 * either expressed or implied, of the Shogun Development Team.
 *
 */


#ifndef _STATIONARYKERNELBASE_H__
#define _STATIONARYKERNELBASE_H__

#include <shogun/lib/config.h>

#include <sholib/common.h>
#include <shogun/kernel/Kernel.h>
#include <shogun/features/Features.h>

namespace shogun
{
/** @brief This is the base class for all stationary kernels.
 * I.e. those kernel functions which only rely on the computed
 * distance d between their input points. They are thus translation
 * invariant (e.g. Gaussian Kernel).
*/
template <class T> class CStationaryKernelBase : public CKernel
{
	public:
		/** default constructor */
		CStationaryKernelBase();

		/** constructor
		 *
		 * @param l features of left-hand side
		 * @param r features of right-hand side
		 */
		CStationaryKernelBase(CFeatures* l, CFeatures* r);

		/** destructor */
		virtual ~CStationaryKernelBase();

		/** returns the name of the class */
		virtual const char* get_name() const { return "StationaryKernelBase";

		virtual EKernelType get_kernel_type()=0;

	protected:
		/** compute kernel function for features a and b
		 * idx_{a,b} denote the index of the feature vectors
		 * in the corresponding feature object
		 * @param idx_a index a
		 * @param idx_b index b
		 * @return computed kernel function at indices a,b
		 */
		virtual float64_t compute(int32_t idx_a, int32_t idx_b)=0;

		/** subtract vector b from vector a
		 * @param idx_a index a
		 * @param idx_b index b
		 * @return difference between a and b, a - b
		 */
		virtual CFeatures get_feature_diff(int32_t idx_a, int32_t idx_b);

	private:
		void init();

	protected:
		/** computed vector difference */
		feature_diff;
};
}
#endif /* _STATIONARYKERNELBASE_H__ */