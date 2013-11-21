#ifndef SEQUENTIALSTATUSSWITCHER_H
#define SEQUENTIALSTATUSSWITCHER_H

#include "AbstractLog.h"

namespace Tinker{

    //! Sequential status switcher
    /*!
        The SequentialStatusSwitcher class is used to keep track of a sequential list of status.
		Current status change whenever Button is enabled. 
        \author Nicola Pezzotti
    */
	template <class Switch>
    class SequentialStatusSwitcher{
	public:
		typedef Switch switch_type;
		typedef unsigned int status_type;
		
    public:
		//! Creates an empty SequentialStatusSwitcher. 
		/*!
			Maximum number of status and current status will be setted to 0
		*/
		SequentialStatusSwitcher();
		//! Returns maximum number of status
		const status_type& numberOfStatus()const;
		//! Returns current status
		/*!
			\return a value bewtween 0 <-> (numberOfStatus()-1)
		*/
		const status_type& status()const;
		//! Sets current status
		void setStatus(status_type status);
		//! Sets maximum number of status
		void setNumberOfStatus(status_type numberOfStatus);
		//! Refreshes the switcher
		void refresh();
		//! Returns a reference to the switch object
		Switch& switcher();
		//! Returns a const reference to the switch object
		const Switch& switcher()const;
		
	private:
		unsigned int _nStatus;
		unsigned int _currentStatus;
		Switch _switcher;
		
	public: 
		//! Logger
		AbstractLog *_log;
    };
	
	template <class Switch>
	SequentialStatusSwitcher<Switch>::SequentialStatusSwitcher():
		_log(0),
		_nStatus(0),
		_currentStatus(0)
	{}
	
	template <class Switch>
	const typename SequentialStatusSwitcher<Switch>::status_type& SequentialStatusSwitcher<Switch>::numberOfStatus()const{
		return _nStatus;
	}
	
	template <class Switch>
	const typename SequentialStatusSwitcher<Switch>::status_type& SequentialStatusSwitcher<Switch>::status()const{
		return _currentStatus;
	}
	
	template <class Switch>
	void SequentialStatusSwitcher<Switch>::setNumberOfStatus(status_type status){
		SECURE_LOG_VAL(_log,"# of status",status);
		_nStatus = status;
	}
	
	template <class Switch>
	void SequentialStatusSwitcher<Switch>::setStatus(status_type status){
		if(status >= _nStatus){
			SECURE_LOG(_log,"Invalid status");
			return;
		}
		SECURE_LOG_VAL(_log,"# of status",status);
		_currentStatus = status;
	}
	
	template <class Switch>
	void SequentialStatusSwitcher<Switch>::refresh(){
		if(_switcher.enabled()){
			_currentStatus++;
			if(_currentStatus>=_nStatus)
				_currentStatus = 0;
		}
	}
	
	template <class Switch>
	Switch& SequentialStatusSwitcher<Switch>::switcher(){
		return _switcher;
	}
	
	template <class Switch>
	const Switch& SequentialStatusSwitcher<Switch>::switcher()const{
		return _switcher;
	}
	

}

#endif
