#include <windows.h>
#include <tchar.h>
#include <Aclapi.h>

int _tmain(int argc, _TCHAR* argv[])
{
	SID_IDENTIFIER_AUTHORITY SIDAuthWorld = SECURITY_WORLD_SID_AUTHORITY;
	PSID pSIDEveryone = NULL;
	if(!AllocateAndInitializeSid(&SIDAuthWorld, 1,
						 SECURITY_WORLD_RID,
						 0, 0, 0, 0, 0, 0, 0,
						 &pSIDEveryone))
	{
		return 1;
	}

	TRUSTEE trustee = {0};
	trustee.pMultipleTrustee = NULL;
	trustee.MultipleTrusteeOperation = NO_MULTIPLE_TRUSTEE;
	trustee.TrusteeForm = TRUSTEE_IS_SID;
	trustee.TrusteeType = TRUSTEE_IS_WELL_KNOWN_GROUP;
	trustee.ptstrName = (LPTSTR)pSIDEveryone;

	EXPLICIT_ACCESS ea = {0};
	ea.grfAccessPermissions = GENERIC_READ | GENERIC_WRITE;
	ea.grfAccessMode = GRANT_ACCESS;
	ea.grfInheritance = NO_INHERITANCE;
	ea.Trustee = trustee;

	PACL pACL = NULL;
	if(ERROR_SUCCESS != SetEntriesInAcl(1,
		&ea,
		NULL,
		&pACL))
	{
		return 1;
	}

	if(ERROR_SUCCESS != SetNamedSecurityInfo(
		_T("C:\\T\\Test.txt"),
		SE_FILE_OBJECT,
		DACL_SECURITY_INFORMATION,
		NULL,
		NULL,
		pACL,
		NULL))
	{
		return 1;
	}

	LocalFree(pACL);
	FreeSid(pSIDEveryone);

	return 0;
}

