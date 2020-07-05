
#include <Context.h>
#include <Project.h>

#include <Math/Vector.h>

using namespace VCLang;

int main()
{
	v3 v {};
	Rotator rotator {};
	bool val = IsReflectableType<Rotator>();

	Context::Initialize();
	auto project = Create<Project>();
	project->Init(".");
	project->LoadAllAssets();
	return 0;
}
