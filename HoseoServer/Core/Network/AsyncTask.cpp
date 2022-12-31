#include "pch.h"
#include "AsyncTask.h"
#include "AsyncDispatcher.h"
#include "AsyncEventSink.h"

CAsyncTask::CAsyncTask(const Callback& callback)
	: CTask(callback)
{
}

CAsyncTask::~CAsyncTask()
{
}

void CAsyncTask::PostTask(CAsyncTask* task)
{
	CAsyncDispatcher::GetInstance()->Enqueue(nullptr, &task->GetBuffer());
}

void CAsyncTask::Execute(CAsyncEventSink* sink)
{
	OnCallbackEvent();
}