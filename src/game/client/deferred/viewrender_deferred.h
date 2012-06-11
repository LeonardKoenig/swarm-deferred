#ifndef VIEWRENDER_DEFERRED_H
#define VIEWRENDER_DEFERRED_H

#include "viewrender.h"

#include "deferred/deferred_shared_common.h"


class CDeferredViewRender : public CViewRender
{
	DECLARE_CLASS( CDeferredViewRender, CViewRender );

public:
					CDeferredViewRender();
	virtual			~CDeferredViewRender( void ) {}

	virtual void	Init( void );
	virtual void	Shutdown( void );

	virtual void	RenderView( const CViewSetup &view, const CViewSetup &hudViewSetup, int nClearFlags, int whatToDraw );

public:

	void			LevelInit( void );
	void			LevelShutdown( void );

	void			ResetCascadeDelay();

	void			ViewDrawSceneDeferred( const CViewSetup &view, int nClearFlags, view_id_t viewID,
		bool bDrawViewModel );

	void			ViewDrawGBuffer( const CViewSetup &view, bool &bDrew3dSkybox, SkyboxVisibility_t &nSkyboxVisible,
		bool bDrawViewModel );
	void			ViewDrawComposite( const CViewSetup &view, bool &bDrew3dSkybox, SkyboxVisibility_t &nSkyboxVisible,
		int nClearFlags, view_id_t viewID, bool bDrawViewModel );

	void			DrawSkyboxComposite( const CViewSetup &view, const bool &bDrew3dSkybox );
	void			DrawWorldComposite( const CViewSetup &view, int nClearFlags, bool bDrawSkybox );

	void			DrawLightShadowView( const CViewSetup &view, int iDesiredShadowmap, def_light_t *l );

protected:

	void			DrawViewModels( const CViewSetup &view, bool drawViewmodel, bool bGBuffer );


private:

	void ProcessDeferredGlobals( const CViewSetup &view );

	void PerformLighting( const CViewSetup &view );

	void RenderCascadedShadows( const CViewSetup &view );

	float m_flRenderDelay[SHADOW_NUM_CASCADES];
};




#endif