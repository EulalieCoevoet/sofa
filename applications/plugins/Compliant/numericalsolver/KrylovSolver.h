#ifndef COMPLIANT_KRYLOVSOLVER_H
#define COMPLIANT_KRYLOVSOLVER_H

#include "IterativeSolver.h"
#include "Response.h"

#include "utils/krylov.h"

#include "assembly/AssembledSystem.h"
#include <sofa/core/objectmodel/BaseObject.h>

#include <Eigen/SparseCholesky>


namespace sofa {
namespace component {
namespace linearsolver {


/// Base class for iterative solvers in the Krylov family (CG, Minres, ...)
class SOFA_Compliant_API KrylovSolver : public IterativeSolver {
  public:
	
	KrylovSolver();				
	
	Data<bool> schur;
	Data<bool> verbose;
    Data<unsigned> restart;
	
	virtual void init();
	
	virtual void solve(vec& x,
	                   const system_type& system,
                       const vec& rhs) const;

	virtual void correct(vec& x,
						 const system_type& system,
						 const vec& rhs,
						 real damping) const;


	virtual void factor(const system_type& sys);
	
  protected:

	virtual void solve_schur(vec& x,
	                         const system_type& system,
	                         const vec& rhs, 
							 real damping = 0) const = 0;
	
	virtual void solve_kkt(vec& x,
	                       const system_type& system,
	                       const vec& rhs,
						   real damping = 0) const = 0;
	
	typedef ::krylov<SReal>::params params_type;
	
	// convenience
	virtual params_type params(const vec& rhs) const;

	// again
    void report(const char* what, const params_type& p) const;

	typedef Response response_type;
	Response::SPtr response;


public:

  Data<bool> parallel;

};


}
}
}

#endif
